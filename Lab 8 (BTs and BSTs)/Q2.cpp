#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Combatant {
    string name;
    int hp;
    int attack;
};

struct Node {
    Combatant data;
    Node* left;
    Node* right;
};

Node* createNode(string name, int hp, int attack) {
    Node* newNode = new Node;
    newNode->data = {name, hp, attack};
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, string name, int hp, int attack) {
    if (!root) return createNode(name, hp, attack);
    if (name < root->data.name) root->left = insert(root->left, name, hp, attack);
    else root->right = insert(root->right, name, hp, attack);
    return root;
}

Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data.name << "(" << root->data.hp << " HP), ";
    inorder(root->right);
}

Node* remove(Node* root, string name) {
    if (!root) return NULL;
    if (name < root->data.name) root->left = remove(root->left, name);
    else if (name > root->data.name) root->right = remove(root->right, name);
    else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = remove(root->right, temp->data.name);
    }
    return root;
}

bool isEmpty(Node* root) {
    return root == NULL;
}

void displayStatus(Node* playerRoot, Node* enemyRoot, int round) {
    cout << "\n===== ROUND " << round << " =====\n";
    cout << "Player Team: "; inorder(playerRoot);
    cout << "\nEnemy Team:  "; inorder(enemyRoot);
    cout << "\n===========================\n";
}

int main() {
    srand(time(0));

    Node* playerTeam = NULL;
    Node* enemyTeam = NULL;

    // Initialize player team
    playerTeam = insert(playerTeam, "Aria", 25, 6);
    playerTeam = insert(playerTeam, "Blaze", 22, 7);
    playerTeam = insert(playerTeam, "Cyrus", 20, 5);
    playerTeam = insert(playerTeam, "Dahlia", 18, 8);
    playerTeam = insert(playerTeam, "Eon", 24, 6);

    // Initialize enemy team
    enemyTeam = insert(enemyTeam, "Vex", 21, 6);
    enemyTeam = insert(enemyTeam, "Raze", 23, 7);
    enemyTeam = insert(enemyTeam, "Nox", 19, 8);
    enemyTeam = insert(enemyTeam, "Kane", 20, 6);
    enemyTeam = insert(enemyTeam, "Zed", 25, 5);

    int round = 1;
    while (!isEmpty(playerTeam) && !isEmpty(enemyTeam)) {
        displayStatus(playerTeam, enemyTeam, round);

        Node* playerFront = findMin(playerTeam);
        Node* enemyFront = findMin(enemyTeam);

        // Player attacks first
        int playerDmg = playerFront->data.attack + rand() % 5;
        enemyFront->data.hp -= playerDmg;
        cout << playerFront->data.name << " attacks " << enemyFront->data.name 
             << " for " << playerDmg << " damage!\n";

        if (enemyFront->data.hp <= 0) {
            cout << enemyFront->data.name << " has been defeated!\n";
            enemyTeam = remove(enemyTeam, enemyFront->data.name);
            if (isEmpty(enemyTeam)) break;
        }

        // Enemy attacks back (if still alive)
        enemyFront = findMin(enemyTeam);
        int enemyDmg = enemyFront->data.attack + rand() % 5;
        playerFront->data.hp -= enemyDmg;
        cout << enemyFront->data.name << " counterattacks " << playerFront->data.name 
             << " for " << enemyDmg << " damage!\n";

        if (playerFront->data.hp <= 0) {
            cout << playerFront->data.name << " has been defeated!\n";
            playerTeam = remove(playerTeam, playerFront->data.name);
        }

        round++;
    }

    if (isEmpty(playerTeam)) cout << "\nENEMIES WIN THE BATTLE!\n";
    else cout << "\nHEROES WIN THE BATTLE!\n";

    return 0;
}
