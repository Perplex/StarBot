# StarBot - Automaton 2017
StarCraft II Bot

## Status (18/11/2017): In-Progress
- Compilable Command Center and SC2 API files pushed (Ceegan)
- All upgrades can be researched (Ceegan)
- Base expansion available (Ceegan)
- Blink kitting based on distance and weapon cooldown (Ceegan)
- "Blink Stalker" strategies and building order(Zhai)

## Todo:
  Race: Protoss

 <dl>
  <dt>Must Do Task:</dt>
  <dd> BotConfig - Strategy “Blink Stalker” (BuildingOrder)</dd>
  <dd> ProductionManager.cpp - Line 35: Build order macro design and triggers. (Cloaked units)</dd>
  <dd> CombatCommander.cpp - Line 63: Attack at specific timing and enough Stalkers.</dd>
  <dd> Unit.cpp - Nexus applys ChronoBoost to buildings if it has power "BlinkTech Research > Weapon/Defend Upgrade > Produce Stalker > Produce Probe".</dd>
  <dd> Wrapgate tile recognization and wrap stalkers directly to front.</dd>
  <dd> ScoutManager.cpp - Scout worker hide outside after scout and build front pylon while attacking starts.</dd>

 <dt>Should Do Task:</dt>
 <dd> BaseLocationManager.cpp - Line 325: Implement method buildingInTheWay to check if there are any units on the tile.</dd>  
 <dd> StrategyManager.cpp - Line 128: Recognize enemy name and apply strategies for special enemy’s army. (Fill BotConfig)</dd>
 <dd> ScoutManager.cpp - Early scout.  Assigning few workers scout the whole map for wide buildings or bases if the main base does not have any tech-building at specific timing.</dd>
 <dd> Squad.cpp - Line 123: Squard detectors.</dd>
    
 <dt>May Do Task:</dt>
 <dd> BuildingManager.cpp - Line 427: Implement basic options for special pylon/cannon spacing.</dd>
 <dd> Second Base implements route block for Photon Cannons defend strategy.</dd>
 <dd> WorkerData.cpp - Line 43: Skip gas workers.</dd>
 <dd> CombatCommander.cpp - Line 316: Defend squard of Sentries’ force field and Stalkers && Line 349: Cannons before attack for zergling rush.</dd>
 <dd> MeleeManager.cpp - Melee units management.</dd>
 <dd> MicroManager.cpp - Line 147: TrainSubUnits (Undefined).</dd>
 <dd> ScoutManager.cpp - Line 186: Get flee route for rescout the enemy’s base.</dd>
</dl>

## Authors
- Ceegan Hale
- Gregory Baker
- Brandon Wielickzo
- Charles Zhai
