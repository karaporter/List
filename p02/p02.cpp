#include "p02.h"
#include <iostream>
#include <fstream>

Node* loadList(string filename) {
    std::ifstream file;
    file.open(filename);
    Node* head = nullptr, *temp;
    while (!file.eof()) {
        int standing;
        Student s;
        file >> s.id >> s.firstname >> s.lastname;
        file >> s.state >> standing >> s.gpa;
        if (standing == 1) {
            s.standing = FR;
        } else if (standing == 2) {
            s.standing = SO;
        } else if (standing == 3) {
            s.standing = JR;
        } else {
            s.standing = SR;
        }
        if (head == nullptr) {
            head = new Node;
            head->data = s;
            head->next = nullptr;
            temp = head;
        } else {
            temp->next = new Node;
            temp = temp->next;
            temp->data = s;
            temp->next = nullptr;
        }
    }
file.close();
return head;
}

void destroyList(Node*& head) {
    Node* temp = nullptr;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

vector<string> getAllIds(Node* head) {
    vector<string> v;
    Node* temp = head;
    while (temp != nullptr) {
        v.push_back(temp->data.id);
        temp = temp->next;
    }
return v;
}

vector<string> getIdsForLastname(Node* head, string lastname) {
    vector<string> v;
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data.lastname == lastname) {
            v.push_back(temp->data.id);
        }
    temp = temp->next;
    }
return v;
}

vector<string> getIdsForGpaStanding(Node* head, float gpa, Standing standing) {
    vector<string> v;
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data.gpa >= gpa && temp->data.standing == standing) {
            v.push_back(temp->data.id);
        }
    temp = temp->next;
    }
return v;
}

vector<string> getIdsForStandingState(Node* head,
                                    Standing standing,
                                    string state) {
    vector<string> v;
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data.standing == standing && temp->data.state == state) {
            v.push_back(temp->data.id);
        }
    temp = temp->next;
    }
return v;
}

vector<string> getFirstLastNames(Node* head, vector<string> ids) {
    vector<string> v;
    Node* temp = head;
    for (int i =0; i < ids.size(); i++) {
    while (temp != nullptr) {
        if (temp->data.id == ids[i]) {
            v.push_back((temp->data.firstname) + " " + (temp->data.lastname));
        }
        temp = temp->next;
    }
    temp = head;
    }
return v;
}
