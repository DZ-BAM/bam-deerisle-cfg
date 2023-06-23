#ifndef BAM_WEAPON
#define BAM_WEAPON

class BAM_Weapon {
    string name;
    ref array<string> attachments;
    ref BAM_Magazine magazine;

    void BAM_Weapon(
            string name,
            ref array<string> attachments,
            ref BAM_Magazine magazine,
    ) {
        this.name = name;
        this.attachments = attachments;
        this.magazine = magazine;
    }

    void addToPlayer(PlayerBase player) {
        this.addToInventory(player.GetInventory());
    }

    void addToInventory(GameInventory inventory) {
        auto weapon = Weapon_Base.Cast(inventory.CreateInInventory(this.name));

        foreach (auto attachment: this.attachments) {
            weapon.GetInventory().CreateInInventory(attachment);
        }

        this.magazine.addToWeapon(weapon);
    }
};

class BAM_Magazine {
    string name;
    int flags;

    void BAM_Magazine(string name, int flags) {
        this.name = name;
        this.flags = flags;
    }

    void addToWeapon(Weapon_Base weapon) {
        weapon.SpawnAmmo(this.name, this.flags);
    }
};

#endif