#ifndef BAM_SPAWN
#define BAM_SPAWN

#include "$CurrentDir:bam-deerisle-cfg/BAM_Scripts/clothing.c"
#include "$CurrentDir:bam-deerisle-cfg/BAM_Scripts/inventory.c"

const ref BAM_Clothing CLOTHING = new BAM_Clothing(
	"ChernarusSportShirt",
	"SlacksPants_Beige",
	"jmc_Military_mountain_boots_black",
	"",
	"",
	"",
);
const ref BAM_Inventory INVENTORY = new BAM_Inventory(
	{"CombatKnife"},
	{
		{
			"Chemlight_White",
			"Chemlight_Yellow",
			"Chemlight_Green",
			"Chemlight_Red",
		},
		{"Apple", "Pear", "Plum"},
	},
	BAM_quantizedItems(),
	{},
);

ref map<string, int> BAM_quantizedItems() {
	auto items = new map<string, int>();
	items["Rag"] = 4;
	return items;
}

void BAM_SetStartingEquipment(PlayerBase player) {
	CLOTHING.applyToPlayer(player);
	INVENTORY.addToPlayer(player);
}

#endif