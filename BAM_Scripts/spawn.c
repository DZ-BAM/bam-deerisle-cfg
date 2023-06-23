const ref TStringArray FOOD = {"Apple", "Pear", "Plum"};
const ref TStringArray CHEM_LIGHTS = {"Chemlight_White", "Chemlight_Yellow", "Chemlight_Green", "Chemlight_Red"};
const string SHOES = "jmc_Military_mountain_boots_black";

void BAM_SetStartingEquipment(PlayerBase player) {
	BAM_SetRandomlyWornRags(player, 4);
	BAM_SetRandomChemlight(player);
	BAM_SetRandomFood(player);
	BAM_SetClothing(player);
}

void BAM_SetRandomlyWornRags(PlayerBase player, int amount) {
	EntityAI body = player.FindAttachmentBySlotName("Body");

	if (body) {
		EntityAI ragEntity = body.GetInventory().CreateInInventory("Rag");
		ItemBase ragItem;

		if (Class.CastTo(ragItem, ragEntity)) {
			ragItem.SetQuantity(amount);
		}
	}
}

void BAM_SetRandomChemlight(PlayerBase player) {
	EntityAI body = player.FindAttachmentBySlotName("Body");

	if (body) {
		body.GetInventory().CreateInInventory(CHEM_LIGHTS.GetRandomElement());
	}
}

void BAM_SetRandomFood(PlayerBase player) {
	player.GetInventory().CreateInInventory(FOOD.GetRandomElement());
}

void BAM_SetClothing(PlayerBase player) {
	EntityAI feet = player.FindAttachmentBySlotName("Feet");
	
	if (feet) {
		feet.GetInventory().CreateInInventory(SHOES);
	} else {
		player.GetInventory().CreateInInventory(SHOES);
	}
}
