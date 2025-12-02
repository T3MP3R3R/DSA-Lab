#include <iostream>
using namespace std;

struct StudentNode {
    int studentID;
    StudentNode* next;
    StudentNode(int id) { studentID = id; next = NULL; }
};

struct HashNode {
    int hashValue;
    int frequency;
    StudentNode* students;
    HashNode* next;
    HashNode(int h) { hashValue = h; frequency = 0; students = NULL; next = NULL; }
};

struct Record {
    int hashValue;
    int f;
    int d;
};

class HashTable {
    HashNode* table[1000];
    int size;

    int hashFunc(int h) { return h % size; }

    bool studentExists(StudentNode* head, int studentID) {
        StudentNode* temp = head;
        while (temp) {
            if (temp->studentID == studentID) return true;
            temp = temp->next;
        }
        return false;
    }

public:
    HashTable(int s = 1000) { size = s; for(int i=0;i<size;i++) table[i]=NULL; }

    void insert(int h, int studentID) {
        int idx = hashFunc(h);
        HashNode* curr = table[idx];
        while (curr) {
            if (curr->hashValue == h) break;
            curr = curr->next;
        }

        if (!curr) {
            curr = new HashNode(h);
            curr->next = table[idx];
            table[idx] = curr;
        }

        curr->frequency++;

        if (!studentExists(curr->students, studentID)) {
            StudentNode* newStudent = new StudentNode(studentID);
            newStudent->next = curr->students;
            curr->students = newStudent;
        }
    }

    int collectSuspicious(Record recs[], int K) {
        int count = 0;
        for (int i = 0; i < size; i++) {
            HashNode* curr = table[i];
            while (curr) {
                int distinctCount = 0;
                StudentNode* s = curr->students;
                while (s) { distinctCount++; s = s->next; }
                if (curr->frequency > K && distinctCount >= 2) {
                    recs[count].hashValue = curr->hashValue;
                    recs[count].f = curr->frequency;
                    recs[count].d = distinctCount;
                    count++;
                }
                curr = curr->next;
            }
        }
        return count;
    }
};

void merge(Record arr[], int l, int m, int r) {
    int n1 = m-l+1, n2 = r-m;
    Record L[n1], R[n2];
    for(int i=0;i<n1;i++) L[i]=arr[l+i];
    for(int i=0;i<n2;i++) R[i]=arr[m+1+i];

    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if (L[i].f > R[j].f) arr[k++] = L[i++];
        else if(L[i].f < R[j].f) arr[k++] = R[j++];
        else {
            if(L[i].d > R[j].d) arr[k++] = L[i++];
            else if(L[i].d < R[j].d) arr[k++] = R[j++];
            else {
                if(L[i].hashValue < R[j].hashValue) arr[k++] = L[i++];
                else arr[k++] = R[j++];
            }
        }
    }
    while(i<n1) arr[k++]=L[i++];
    while(j<n2) arr[k++]=R[j++];
}

// Merge sort
void mergeSort(Record arr[], int l, int r) {
    if(l<r){
        int m = l + (r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main() {
    int n, K;
    cout << "Enter number of submissions n: ";
    cin >> n;
    cout << "Enter plagiarism threshold K: ";
    cin >> K;

    int H[n], ID[n];
    cout << "Enter submission hashes:\n";
    for(int i=0;i<n;i++) cin >> H[i];
    cout << "Enter student IDs:\n";
    for(int i=0;i<n;i++) cin >> ID[i];

    HashTable ht;
    for(int i=0;i<n;i++) ht.insert(H[i], ID[i]);

    Record recs[n];
    int count = ht.collectSuspicious(recs, K);

    if(count==0){
        cout << "NO SUSPICIOUS HASHES " << endl;
    } else {
        mergeSort(recs, 0, count-1);
        for(int i=0;i<count;i++)
            cout << recs[i].hashValue << " " << recs[i].f << " " << recs[i].d << endl;
    }

    return 0;
}