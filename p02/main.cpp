#include <iostream>
#include "p02.h"

using std::cout;
using std::endl;


int main() {
    Node* head = loadList("data.txt");

    vector<string> all = getAllIds(head);
    cout << all.size() << endl;                           // Should be 50
    cout << "----------" << endl;
    vector<string> piff = getIdsForLastname(head, "Piff");
    for (int i = 0; i < piff.size(); i++) {
        cout << piff[i] << endl;
    }                                                     // Should be W4779
    cout << "----------" << endl;
    vector<string> threeJr = getIdsForGpaStanding(head, 3.0, JR);
    for (int i = 0; i < threeJr.size(); i++) {
        cout << threeJr[i] << endl;
    }                                                     // Should be
                                                          // W0304
                                                          // W0128
                                                          // W0099
    cout << "----------" << endl;
    vector<string> frSC = getIdsForStandingState(head, FR, "SC");
    for (int i = 0; i < frSC.size(); i++) {
        cout << frSC[i] << endl;
    }                                                     // Should be W2956
    cout << "----------" << endl;
    vector<string> names = getFirstLastNames(head, threeJr);
    for (int i = 0; i < names.size(); i++) {
        cout << names[i] << endl;
    }                                                     // Should be
                                                          // Farrel Danter
                                                          // Richmond Cohalan
                                                          // Mable Busain
    cout << "----------" << endl;

    destroyList(head);

    return 0;
}
