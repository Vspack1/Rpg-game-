#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Thêm enum cho các chủng tộc và nghề nghiệp
enum Race { HUMAN, ELF, DWARF, ORC };
enum Class { WARRIOR, MAGE, ARCHER, ROGUE };

// Thêm class Monster trước class Player
class Monster {
private:
    string name;
    int health;
    int attack;
    int expReward;

public:
    Monster(string n, int h, int atk, int exp) 
        : name(n), health(h), attack(atk), expReward(exp) {}
    
    void takeDamage(int damage) {
        health -= damage;
        if(health < 0) health = 0;
    }  

    bool isAlive() const {
        return health > 0;
    }

    int getExpReward() const {
        return expReward;
    }

    string getName() const {
        return name;
    }

    int getHealth() const {
        return health;
    }

    int getAttack() const {
        return attack;
    }
};

class Player {
private:
    // Thêm các thuộc tính mới
    Race race;
    Class playerClass;
    int mana;
    int gold;
    vector<string> inventory;
    map<string, int> skills;
    int karma;
    string name;
    int health;
    int attack; 
    int level;
    int exp;

public:
    Player(string n, Race r, Class c) : name(n), race(r), playerClass(c) {
        health = 100;
        mana = 100;
        attack = 10;
        level = 1;
        exp = 0;
        gold = 0;
        karma = 0;
        
        // Khởi tạo kỹ năng dựa trên nghề nghiệp
        initializeSkills();
    }

    void initializeSkills() {
        switch(playerClass) {
            case WARRIOR:
                skills["Slash"] = 1;
                skills["Shield Block"] = 1;
                break;
            case MAGE:
                skills["Fireball"] = 1;
                skills["Ice Shield"] = 1;
                break;
            // ... thêm các nghề nghiệp khác
        }
    }

    // Thêm các phương thức mới
    void addItem(string item) {
        inventory.push_back(item);
    }

    void useSkill(string skillName, Monster &target) {
        if(skills.find(skillName) == skills.end()) {
            cout << "Kỹ năng không tồn tại!\n";
            return;
        }

        int skillLevel = skills[skillName];
        if(skillName == "Fireball" && mana >= 20) {
            int damage = 15 * skillLevel;
            target.takeDamage(damage);
            mana -= 20;
            cout << "Sử dụng Fireball gây " << damage << " sát thương!\n";
        }
        // ... thêm các kỹ năng khác
    }

    void changeKarma(int amount) {
        karma += amount;
        cout << (amount > 0 ? "Danh tiếng tăng!" : "Danh tiếng giảm!") << "\n";
    }
    
    // ... existing methods ...

    void gainExp(int amount) {
        exp += amount;
        // Kiểm tra level up
        while(exp >= level * 100) {  // 100 exp mỗi level
            levelUp();
        }
    }

    void levelUp() {
        level++;
        health += 20;
        mana += 10;
        attack += 5;
        cout << "Lên cấp! Cấp độ hiện tại: " << level << "\n";
    }
};

// Thêm class cho nhiệm vụ
class Quest {
private:
    string title;
    string description;
    int rewardGold;
    int rewardExp;
    bool completed;

public:
    Quest(string t, string d, int gold, int exp) 
        : title(t), description(d), rewardGold(gold), rewardExp(exp), completed(false) {}
    
    void complete(Player &player) {
        if(!completed) {
            player.gainExp(rewardExp);
            // Thêm gold cho player
            completed = true;
            cout << "Hoàn thành nhiệm vụ: " << title << "!\n";
        }
    }
};

// Thêm class cho vật phẩm
class Item {
private:
    string name;
    int price;
    string effect;

public:
    Item(string n, int p, string e) : name(n), price(p), effect(e) {}
    // ... các phương thức khác
};

// Cập nhật hàm battle với hệ thống kỹ năng mới
void battle(Player &player, Monster &monster) {
    // ... existing battle code ...
    cout << "\n1. Tấn công thường\n";
    cout << "2. Sử dụng kỹ năng\n";
    cout << "3. Sử dụng vật phẩm\n";
    cout << "4. Chạy trốn\n";
    
    // ... implement new battle options ...
}

int main() {
    string playerName;
    int raceChoice, classChoice;
    
    cout << "Nhập tên nhân vật của bạn: ";
    cin >> playerName;
    
    do {
        cout << "Chọn chủng tộc (0: Human, 1: Elf, 2: Dwarf, 3: Orc): ";
        cin >> raceChoice;
    } while(raceChoice < 0 || raceChoice > 3);
    
    do {
        cout << "Chọn nghề nghiệp (0: Warrior, 1: Mage, 2: Archer, 3: Rogue): ";
        cin >> classChoice;
    } while(classChoice < 0 || classChoice > 3);
    
    // Tạo nhân vật
    Player player(playerName, static_cast<Race>(raceChoice), static_cast<Class>(classChoice));
    
    // Vòng lặp game chính
    bool running = true;
    while(running) {
        cout << "\n=== MENU CHÍNH ===\n";
        cout << "1. Xem thông tin nhân vật\n";
        cout << "2. Đi săn quái vật\n";
        cout << "3. Nghỉ ngơi\n";
        cout << "4. Xem nhiệm vụ\n";
        cout << "5. Mở túi đồ\n";
        cout << "6. Ghé thăm cửa hàng\n";
        cout << "0. Thoát game\n";
        cout << "Lựa chọn của bạn: ";
        
        int choice;
        cin >> choice;
        
        switch(choice) {
            case 0:
                running = false;
                break;
            case 1:
                // Thêm code hiển thị thông tin nhân vật
                break;
            case 2:
                // Thêm code chiến đấu với quái vật
                break;
            // Thêm các case khác...
            default:
                cout << "Lựa chọn không hợp lệ!\n";
        }
    }
    
    cout << "Cảm ơn bạn đã chơi game!\n";
    return 0;
}