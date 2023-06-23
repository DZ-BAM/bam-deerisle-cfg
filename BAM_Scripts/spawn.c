#ifndef BAM_SPAWN
#define BAM_SPAWN
#include "$CurrentDir:bam-deerisle-cfg/BAM_Scripts/clothing.c"
#include "$CurrentDir:bam-deerisle-cfg/BAM_Scripts/inventory.c"

const autoptr BAM_Clothing CLOTHING = new BAM_Clothing(
	"ChernarusSportShirt",
	"SlacksPants_Beige",
	"jmc_Military_mountain_boots_black",
	"",
	"",
	"",
);
const autoptr BAM_Inventory INVENTORY = new BAM_Inventory(
	{"CombatKnife", "Rag"},
	{
		{"Chemlight_White", "Chemlight_Yellow", "Chemlight_Green", "Chemlight_Red"},
		{"Apple", "Pear", "Plum"},
	},
);

void BAM_SetStartingEquipment(PlayerBase player) {
	CLOTHING.applyTo(player);
	INVENTORY.addToPlayer(player);
}

#endif