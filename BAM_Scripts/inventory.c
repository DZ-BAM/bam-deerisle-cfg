#ifndef BAM_INVENTORY
#define BAM_INVENTORY

class BAM_Inventory {
    array<string> items;
    array<array<string>> random_items;
    map<string, int> quantized_items;

    void BAM_Inventory(
            array<string> items,
            array<array<string>> random_items,
            map<string, int> quantized_items,
    ) {
        this.items = items;
        this.random_items = random_items;
        this.quantized_items = quantized_items;
	}

    void addToPlayer(PlayerBase player) {
        this.addToInventory(player.GetInventory());
    }

    void addToInventory(GameInventory inventory) {

        foreach (auto item: this.items) {
            inventory.CreateInInventory(item);
        }

        foreach (auto selection: this.random_items) {
            inventory.CreateInInventory(selection.GetRandomElement());
        }

        this.addQuantizedItemsToInventory(inventory);
    }

    void addQuantizedItemsToInventory(GameInventory inventory) {
        EntityAI entity;
        ItemBase item;        
        
        foreach (auto name, auto quantity: this.quantized_items) {
            entity = inventory.CreateInInventory(name);

            if (Class.CastTo(item, entity)) {
                item.SetQuantity(quantity);
            }
        }
    }
};

#endif