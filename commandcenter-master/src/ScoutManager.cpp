#include "ScoutManager.h"
#include "CCBot.h"
#include "Util.h"

ScoutManager::ScoutManager(CCBot & bot)
    : m_bot             (bot)
    , m_scoutUnit       ()
    , m_numScouts       (0)
    , m_scoutUnderAttack(false)
    , m_scoutStatus     ("None")
    , m_previousScoutHP (0)
{
}

void ScoutManager::onStart()
{

}

void ScoutManager::onFrame()
{
    moveScouts();
    drawScoutInformation();
}

void ScoutManager::setWorkerScout(const Unit & unit)
{
    // if we have a previous worker scout, release it back to the worker manager
    if (m_scoutUnit.isValid())
    {
        m_bot.Workers().finishedWithWorker(m_scoutUnit);
    }

    m_scoutUnit = unit;
    m_bot.Workers().setScoutWorker(m_scoutUnit);
}

void ScoutManager::drawScoutInformation()
{
    if (!m_bot.Config().DrawScoutInfo)
    {
        return;
    }

    std::stringstream ss;
    ss << "Scout Info: " << m_scoutStatus;

    m_bot.Map().drawTextScreen(0.1f, 0.6f, ss.str());
}

void ScoutManager::moveScouts()
{
    auto workerScout = m_scoutUnit;
    if (!workerScout.isValid()) { return; }

    // get the enemy base location, if we have one
    const BaseLocation * enemyBaseLocation = m_bot.Bases().getPlayerStartingBaseLocation(Players::Enemy);
	static std::vector<const BaseLocation *> lastSeenBases = m_bot.Bases().getBaseLocations();

    int scoutDistanceThreshold = 20;

	if (enemyBaseLocation) {
		m_scoutStatus = "Enemy base known, exploring";

		for (auto Location : m_bot.Bases().getBaseLocations())
		{

			// if we haven't explored it yet then scout it out
			// TODO: this is where we could change the order of the base scouting, since right now it's iterator order
			if (!Location->isExplored() && m_bot.Bases().getOccupiedBaseLocations(Players::Enemy).find(Location) == m_bot.Bases().getOccupiedBaseLocations(Players::Enemy).end() && m_bot.Bases().getOccupiedBaseLocations(Players::Self).find(Location) == m_bot.Bases().getOccupiedBaseLocations(Players::Self).end())
			{
				m_scoutUnit.move(Location->getPosition());	
				return;
			}
		}
		
		if (lastSeenBases[0]->isOccupiedByPlayer(Players::Enemy) || enemyBaseLocation == lastSeenBases[0] || lastSeenBases[0]->isOccupiedByPlayer(Players::Self)) {
			lastSeenBases.erase(lastSeenBases.begin());
		}

		if (lastSeenBases[0]->getPosition().x == m_scoutUnit.getPosition().x && lastSeenBases[0]->getPosition().y == m_scoutUnit.getPosition().y) {
			auto temp = lastSeenBases[0];
			lastSeenBases.erase(lastSeenBases.begin());
			lastSeenBases.push_back(temp);
		}

		m_scoutUnit.move(lastSeenBases[0]->getPosition());
		return;
	}
	else {
		m_scoutStatus = "Enemy base unknown, searching";

		for (const BaseLocation * Location : m_bot.Bases().getStartingBaseLocations())
		{
			// if we haven't explored it yet then scout it out
			// TODO: this is where we could change the order of the base scouting, since right now it's iterator order
			if (!m_bot.Map().isExplored(Location->getPosition()))
			{
				m_scoutUnit.move(Location->getPosition());
				return;
			}
		}
	}

}

Unit ScoutManager::closestEnemyWorkerTo(const CCPosition & pos) const
{
    if (!m_scoutUnit.isValid()) { return Unit(); }

    Unit enemyWorker;
    float minDist = std::numeric_limits<float>::max();

    // for each enemy worker
    for (auto & unit : m_bot.UnitInfo().getUnits(Players::Enemy))
    {
        if (unit.getType().isWorker())
        {
            float dist = Util::Dist(unit, m_scoutUnit);

            if (dist < minDist)
            {
                minDist = dist;
                enemyWorker = unit;
            }
        }
    }

    return enemyWorker;
}
bool ScoutManager::enemyWorkerInRadiusOf(const CCPosition & pos) const
{
    for (auto & unit : m_bot.UnitInfo().getUnits(Players::Enemy))
    {
        if (unit.getType().isWorker() && Util::Dist(unit, pos) < 10)
        {
            return true;
        }
    }

    return false;
}

CCPosition ScoutManager::getFleePosition() const
{
    // TODO: make this follow the perimeter of the enemy base again, but for now just use home base as flee direction
    return m_bot.GetStartLocation();
}