# StarBot - Automaton 2017
StarCraft II Bot

## Status (11/08/2017): In-Progress
- Compilable Command Center and SC2 API files pushed


## Todo:
  Race: Protoss

 <dl>
  <dt>Must Do Task:</dt>
  <dd> BotConfig - Strategy “Blink Stalker” (BuildingOrder)</dd>
  <dd> UnitInfoManager.cpp - Stalker Blink abilities.</dd>
  <dd> ProductionManager.cpp - Line 35: Build order macro design and triggers. (Cloaked units)</dd>
  <dd> Line 69: Implement for early second base.</dd>
  <dd> Line 177: Upgrade for Blink abilities and Attack/Defence upgrades.</dd>
  <dd> CombatCommander.cpp - Line 63: Attack at specific timing and enough Stalkers.</dd>
  <dd> RangedManager.cpp - Line 47: BLINK KITING && Line 67: Target line.</dd>


 <dt>Should Do Task:</dt>
 <dd> BaseLocationManager.cpp - Line 325: Implement method buildingInTheWay to check if there are any units on the tile.</dd>  
 <dd> StrategyManager.cpp - Line 128: Recognize enemy name and apply strategies for special enemy’s army. (Fill BotConfig)</dd>
 <dd> BuildingManager.cpp - Line 427: Implement basic options for special pylon/cannon spacing.</dd>
 <dd> ScoutManager.cpp - Early scout.  Assigning few workers scout the whole map for wide buildings or bases if the main base does not have any tech-building at specific timing.</dd>
 <dd> Squad.cpp - Line 123: Squard detectors.</dd>
    
    
 <dt>May Do Task:</dt>
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
