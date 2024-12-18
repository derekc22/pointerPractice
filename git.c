//
// Created by Derek Chibuzor on 8/5/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[10];
} Person;

typedef struct {
    Person* pax[3];
} Fuselage;

typedef struct {
    char pilot[20];
    Fuselage* planeFuselage;
} Plane;

void addPaxPtr(Fuselage* myFuselage, Person* newPax, int index) {
    (myFuselage->pax)[index] = newPax;
}

Plane* makePlanePtr(Fuselage* myFuselage, char plt[20]) {
    Plane* myPlanePtr = (Plane*) malloc(sizeof(Plane));
    myPlanePtr->planeFuselage = myFuselage;
    strcpy(myPlanePtr->pilot, plt);

    return myPlanePtr;
}

void printPlanePtr(Plane myPlanePtr) {
    printf("Crew: %s", myPlanePtr.pilot);
    printf("\n");

    printf("Pax:");
    for (int i = 0; i <= 2; i++) {
        printf("[%s] ", (*(((myPlanePtr.planeFuselage)->pax)[i])).name);
    }
    printf("\n\n");
}

int main() {
    Person p1 = {"Doug"};
    Person p2 = {"Tim"};
    Person p3 = {"Mike"};

    Fuselage fuselage;
    addPaxPtr(&fuselage, &p1, 0);
    addPaxPtr(&fuselage, &p2, 1);
    addPaxPtr(&fuselage, &p3, 2);

    Plane* temp = makePlanePtr(&fuselage, "Thomas");

    Plane myPlane = *temp;

    printPlanePtr(myPlane);

    free(temp);

    return 0;
}
