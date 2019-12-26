#include <string>
#include <vector>

using std::string;
using std::vector;

enum Standing { FR, SO, JR, SR };

struct Student {
    string id;
    string firstname;
    string lastname;
    string state;
    Standing standing;
    float gpa;
};

struct Node {
    Student data;
    Node* next;
};


Node* loadList(string filename);
void destroyList(Node*& head);
vector<string> getAllIds(Node* head);
vector<string> getIdsForLastname(Node* head, string lastname);
vector<string> getIdsForGpaStanding(Node* head, float gpa, Standing standing);
vector<string> getIdsForStandingState(Node* head,
                                      Standing standing,
                                      string state);
vector<string> getFirstLastNames(Node* head, vector<string> ids);
