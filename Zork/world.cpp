#include "stdafx.h"
#include "world.h"
#include "item.h"
#include "room.h"
#include "exit.h"
#include "creature.h"
#include "player.h"
#include "globals.h"
#include "monster.h"
#include "npc.h"
#include "quest.h"

World::World() {
	entities = vector<Entity*>();
	
	Item *sword = new Item("Sword", "Increment your attack (+3)", ITEM_TYPE::WEAPON, 3);
	entities.push_back(sword);
	Item *chest = new Item("Chest", "A chest that maybe contains something", ITEM_TYPE::CONTAINER);
	entities.push_back(chest);
	chest->contains.push_back(sword);

	Item *spear = new Item("Rusty Spear", "A rusty spear. Increase your attack (+1)", ITEM_TYPE::WEAPON, 5, 70);
	entities.push_back(spear);
	Item *dagger = new Item("Silver Dagger", "A silver dagger. Increase your attack (+3)", ITEM_TYPE::WEAPON, 4, 50);
	entities.push_back(dagger);
	Item *knife = new Item("Sharp Knife", "A sharp knife. Increase your attack (+2)", ITEM_TYPE::WEAPON, 2, 15);
	entities.push_back(knife);

	Item *small_red_potion = new Item("Small red potion", "A small vial with reddish substance. Recovers 10 HP", ITEM_TYPE::CONSUMABLE, 10, 15);
	entities.push_back(small_red_potion);
	Item *big_red_potion = new Item("Big red potion", "A big vial with reddish substance. Recovers 20 HP", ITEM_TYPE::CONSUMABLE, 20, 25);
	entities.push_back(big_red_potion);
	Item *small_yellow_potion = new Item("Small yellow potion", "A vial with yellowish substance. Recovers 15 HP", ITEM_TYPE::CONSUMABLE, 15, 20);
	entities.push_back(small_yellow_potion);
	Item *big_yellow_potion = new Item("Small yellow potion", "A vial with yellowish substance. Recovers 25 HP", ITEM_TYPE::CONSUMABLE, 25, 30);
	entities.push_back(big_yellow_potion);

	Room *beach = new Room("Beach", "A nice beach");
	entities.push_back(beach);
	Room *forest = new Room("Forest", "A dark forest");
	entities.push_back(forest);
	Room *dock = new Room("Dock", "A small dock full of small boats and fishy smell.");
	entities.push_back(dock);
	Room *village = new Room("Village", "A small a peaceful village");
	entities.push_back(village);
	Room *chaman_hut = new Room("Chaman's hut", "A poor hut");
	entities.push_back(chaman_hut);
	Room *mountain = new Room("Mountain", "You can see the whole island from up here");
	entities.push_back(mountain);
	Room *plain = new Room("Great Plain", "A great green plain");
	entities.push_back(plain);
	Room *explorer_basecamp = new Room("Explorer's Basecamp", "A small camp of egxplorers. Everything is stirred up even though the fire is still hot. Among the campsites there are human remains and blood");
	entities.push_back(explorer_basecamp);
	Room *forest_north = new Room("Forest", "You are surrounded by trees You can feel a tranquility that bothers you ...");
	entities.push_back(forest_north);
	Room *forest_clear = new Room("Clear", "A clearing that delimits the forest");
	entities.push_back(forest_clear);
	Room *forest_east = new Room("Forest", "You are surrounded by trees You can feel a tranquility that bothers you ...");
	entities.push_back(forest_east);
	Room *cave_entry = new Room("Cave entry", "There is a cave that gives off bad smell");
	entities.push_back(cave_entry);
	Room *troll_cave = new Room("Troll's cave", "You can smell the nauseating smell of corpses rotting, while you imagine you step on the bones of what you believe are human remains");
	entities.push_back(troll_cave);

	Exit *dock_village = new Exit("Road", "A small road that connects the port and the village", dock, village, GAME_DIRECTION::EAST);
	entities.push_back(dock_village);
	Exit *village_beach = new Exit("Path", "A small path that connects the village and the beach", village, beach, GAME_DIRECTION::SOUTH);
	entities.push_back(village_beach);
	Exit *village_plain = new Exit("Road", "A small road that connects the village and the great plain", village, plain, GAME_DIRECTION::EAST);
	entities.push_back(village_plain);
	Exit *plain_mountain = new Exit("Path", "A small path that connects the village and the mountain", plain, mountain, GAME_DIRECTION::NORTH);
	entities.push_back(plain_mountain);
	Exit *beach_chaman = new Exit("Path", "", beach, chaman_hut, GAME_DIRECTION::EAST);
	entities.push_back(beach_chaman);
	Exit *chaman_plain = new Exit("Path", "", chaman_hut, plain, GAME_DIRECTION::NORTH);
	entities.push_back(chaman_plain);
	Exit *plain_basecamp = new Exit("Path", "", plain, explorer_basecamp, GAME_DIRECTION::EAST);
	entities.push_back(plain_basecamp);
	Exit *basecamp_forest_north = new Exit("Path", "", explorer_basecamp, forest_north, GAME_DIRECTION::NORTH);
	entities.push_back(basecamp_forest_north);
	Exit *basecamp_forest_east = new Exit("Path", "", explorer_basecamp, forest_east, GAME_DIRECTION::EAST);
	entities.push_back(basecamp_forest_east);
	Exit *forest_north_forest_clear = new Exit("Path", "", forest_north, forest_clear, GAME_DIRECTION::EAST);
	entities.push_back(forest_north_forest_clear);
	Exit *forest_east_forest_clear = new Exit("Path", "", forest_east, forest_clear, GAME_DIRECTION::NORTH);
	entities.push_back(forest_east_forest_clear);
	Exit *forest_clear_cave_entry = new Exit("Path", "", forest_clear, cave_entry, GAME_DIRECTION::NORTH);
	entities.push_back(forest_clear_cave_entry);
	Exit *cave_entry_troll_cave = new Exit("Path", "", cave_entry, troll_cave, GAME_DIRECTION::NORTH);
	entities.push_back(cave_entry_troll_cave);
	

	Monster *giant_crab = new Monster("Giant crab", "A huge crab", beach, 6, 1);
	entities.push_back(giant_crab);
	Monster *giant_snake = new Monster("Giant snake", "A giant black snake", mountain, 9, 3);
	entities.push_back(giant_snake);
	Monster *direwolf = new Monster("Direwolf", "A giant black wolf with blood-like eyes", forest_north, 15, 5);
	entities.push_back(direwolf);
	
	
	Npc *fisher = new Npc("Old fisherman", "An old man that seems to have been fishing all his life", dock, "Hey kid! Are you the hunter we were hoping for? You should talk to the mayor. He is in the village going east.", NPC_TYPE::SPEAKER);
	entities.push_back(fisher);
	Npc *blacksmith = new Npc("Blacksmith", "A big strong man", village, "Do you need some weapons? I have the best prices in the village", NPC_TYPE::TRADER);
	entities.push_back(blacksmith);
	Npc *chaman = new Npc("Chaman", "An old and strange man", chaman_hut, "I have some potions that maybe help to you in your journey. Do you want to buy something?", NPC_TYPE::TRADER);
	entities.push_back(chaman);
	Npc *mayor = new Npc("Mayor", "", village, "I know you are here for the troll that killed some of us two weeks ago but could you help us with other problems? We would be very grateful. If you want more info about the troll go east and talk to explorers.", NPC_TYPE::SPEAKER);
	entities.push_back(mayor);
	Npc *explorer_quest = new Npc("Explorer", "", plain, "Oh god ... I saw him I swear I saw him ... a black shadow with ruby ​​eyes ... he attacked us one by one ... I think I'm the only one left...", NPC_TYPE::SPEAKER);

	Quest *crab_request = new Quest(giant_crab, 10, "There is a giant crab on the beach. It is south of here. Lately it is attacking fishermans and children who are going to play there. Could you handle it?");
	Quest *snake_quest = new Quest(giant_snake, 25, "There is a giant serpent that has devoured some guards and cattle. You have to go east until you reach the great plain and then north to find it. Could you help us with it?");
	Quest *direwolf_quest = new Quest(direwolf, 50, "Could you find the beast to revenge for me? I would be eternally grateful. It hides in the forest around the camp to the east");
	
	mayor->quests.push_back(crab_request);
	mayor->quests.push_back(snake_quest);

	explorer_quest->quests.push_back(direwolf_quest);

	explorer_basecamp->contains.push_back(chest);

	blacksmith->contains.push_back(spear);
	blacksmith->contains.push_back(dagger);
	blacksmith->contains.push_back(knife);

	chaman->contains.push_back(small_red_potion);
	chaman->contains.push_back(big_red_potion);
	chaman->contains.push_back(small_yellow_potion);
	chaman->contains.push_back(big_yellow_potion);
	
	player = new Player(dock, 30, 1);
	final_boss = new Monster("Troll", "A huge troll", troll_cave, 25, 6);

	player->Look();
}


World::~World() {
	for each (auto element in entities) {
		if (element != NULL) {
			delete element;
			element = NULL;
		}
	}
	entities.clear();
	delete player;
	player = NULL;
	delete final_boss;
	final_boss = NULL;
}

GAME_STATE World::Update(const vector<string> *arguments) {
	player->Do(arguments);
	for each (auto entity in entities) {
		entity->Update();
	}
	if (!player->IsLive())
		return GAME_STATE::GAME_OVER;
	if (!final_boss->IsLive())
		return GAME_STATE::END;

	return GAME_STATE::CONTINUE;
}