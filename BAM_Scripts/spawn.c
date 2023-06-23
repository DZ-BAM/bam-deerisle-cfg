#ifndef BAM_SPAWN
#define BAM_SPAWN

#include "$CurrentDir:bam-deerisle-cfg/BAM_Scripts/clothing.c"
#include "$CurrentDir:bam-deerisle-cfg/BAM_Scripts/inventory.c"

void BAM_SetStartingEquipment(PlayerBase player) {
	auto QUANTIZED_ITEMS = new map<string, int>();
	QUANTIZED_ITEMS["Rags"] = 4;

	auto CLOTHING = new BAM_Clothing(
		"ChernarusSportShirt",
		"SlacksPants_Beige",
		"jmc_Military_mountain_boots_black",
		"",
		"",
		"",
	);

	array<string> ITEMS = {"CombatKnife"};
	array<string> CHEMLIGHTS = {
		"Chemlight_White",
		"Chemlight_Yellow",
		"Chemlight_Green",
		"Chemlight_Red",
	};
	array<string> FRUITS = {"Apple", "Pear", "Plum"};
	array<array<string>> RANDOM_ITEMS = {CHEMLIGHTS, FRUITS};
	auto INVENTORY = new BAM_Inventory(ITEMS, RANDOM_ITEMS, QUANTIZED_ITEMS);

	CLOTHING.applyTo(player);
	INVENTORY.addToPlayer(player);
}

#endif