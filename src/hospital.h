#ifndef HOSPITALH
#define HOSPITALH



#include <stdio.h>
#include <string.h>


#define NUMSPECIALTIES    4
#define NUMWARDS          4
#define MAXBEDSPERWARD    20
#define MAXPATIENTS       100


static const int specialtyID[NUMSPECIALTIES]        = {1, 2, 3, 4};

static const char *specialtyName[NUMSPECIALTIES] = {
    "General Practice (OPD)",
    "Paediatrics",
    "Cardiology",
    "Neurology"
};

static const double baseFee[NUMSPECIALTIES]          = {1500.00, 2500.00, 4500.00, 5000.00};
static const int    consultTimeMins[NUMSPECIALTIES]  = {15, 20, 30, 30};
static const int    dailyPatientCap[NUMSPECIALTIES]  = {30, 20, 12, 10};


static const int wardID[NUMWARDS]        = {1, 2, 3, 4};

static const char *wardName[NUMWARDS] = {
    "General Ward",
    "Paediatric Ward",
    "Surgical Ward",
    "ICU (Intensive Care Unit)"
};

static const double dailyBedRate[NUMWARDS]  = {3000.00, 6000.00, 12000.00, 25000.00};
static const int    totalBedCapacity[NUMWARDS] = {20, 10, 10, 5};


extern int bedOccupancy[NUMWARDS][MAXBEDSPERWARD];


extern int queueCount[NUMSPECIALTIES];


void initBedOccupancy(void);
void printBedStatus(void);
int  findAvailableBed(int wardIndex);
int  getWardIndexById(int id);
int  getSpecialtyIndexById(int id);

#endif
