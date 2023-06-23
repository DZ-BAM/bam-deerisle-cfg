#ifndef BAM_INVENTORY
#define BAM_INVENTORY

typedef array<array<string>> BAM_ItemSelections;
typedef array<BAM_QuantizedItem> BAM_QuantizedItems;

class BAM_Inventory {
    array<string> items;
    BAM_ItemSelections random_items;
    BAM_QuantizedItems quantized_items;

    void BAM_Inventory(
            array<string> items,
            BAM_ItemSelections random_items,
            BAM_QuantizedItems quantized_items,
    ) {
        this.items = items;
        this.random_items = random_items;
        this.quantized_items = quantized_items;
	}

    void addToPlayer(PlayerBase player) {
        this.addToInventory(player.GetInventory());
    }

    void addToInventory(GameInventory inventory) {
        if (this.items) {
            foreach (auto item: this.items) {
                inventory.CreateInInventory(item);
            }
        }

        if (this.random_items) {
            foreach (auto selection: this.random_items) {
                inventory.CreateInInventory(selection.GetRandomElement());
            }
        }

        if (this.quantized_items) {
            foreach (auto quantized_item: this.quantized_items) {
                quantized_item.addToInventory(inventory);
            }
        }
    }
};

class BAM_QuantizedItem {
    string name;
    int quantity;

    void BAM_QuantizedItem(string name, int quantity) {
        this.name = name;
        this.quantity = quantity;
    }

    void addToInventory(GameInventory inventory) {
        EntityAI entity = inventory.CreateInInventory(this.name);
        ItemBase item;        
        
        if (Class.CastTo(item, entity)) {
            item.SetQuantity(this.quantity);
        }
    }
};

#endif