#ifndef HEADER_H
#define HEADER_H
#include <string>
#include <QLinkedList>

class campus
{
    int distance;
    const char* campusName;
    QLinkedList<const char*> souvenirs;

public:
    campus() : distance{0}, campusName{"NULL"} {};
    campus(int inpDist, const char* inpName) : distance{inpDist}, campusName{inpName} {};
    campus(int inpDist, const char* inpName, QLinkedList<const char*> inpSouv) : distance{inpDist}, campusName{inpName}
    {
        for(int i = 0; i < inpSouv.size(); i++)
            souvenirs.push_back(*(inpSouv.begin()+i));
    };
    const char* getName() {return campusName;};
    int getDistance() {return distance;};
    const char* getSouvenir(int n) {return (*(souvenirs.begin()+n));};
    int numberOfSouvenirs() {return souvenirs.size();};
};

#endif // HEADER_H
