#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct City {
    char name[50];
    double x;
    double y;
    struct City *next;
} City;

typedef struct {
    City *head;
} CityList;

void initCityList(CityList *list) {
    list->head = NULL;
}

void addCity(CityList *list, const char *name, double x, double y) {
    City *newCity = (City *)malloc(sizeof(City));
    strncpy(newCity->name, name, sizeof(newCity->name));
    newCity->x = x;
    newCity->y = y;
    newCity->next = NULL;

    if (list->head == NULL) {
        list->head = newCity;
    } else {
        City *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newCity;
    }
}

void findCityByName(CityList *list, const char *name) {
    City *current = list->head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("城市名: %s, 位置坐标: (%.2lf, %.2lf)\n", current->name, current->x, current->y);
            return;
        }
        current = current->next;
    }
    printf("城市 %s 未找到\n", name);
}

void findCitiesInRadius(CityList *list, double x, double y, double radius) {
    printf("在半径 %.2lf 内的城市：\n", radius);
    City *current = list->head;
    while (current != NULL) {
        double distance = sqrt(pow(current->x - x, 2) + pow(current->y - y, 2));
        if (distance <= radius) {
            printf("城市名: %s, 位置坐标: (%.2lf, %.2lf), 距离: %.2lf\n",
                current->name, current->x, current->y, distance);
        }
        current = current->next;
    }
}

void freeCityList(CityList *list) {
    City *current = list->head;
    while (current != NULL) {
        City *temp = current;
        current = current->next;
        free(temp);
    }
    list->head = NULL;
}

int main() {
    CityList cities;
    initCityList(&cities);

    addCity(&cities, "City1", 10.0, 20.0);
    addCity(&cities, "City2", 15.0, 25.0);
    addCity(&cities, "City3", 30.0, 40.0);

    // 查找城市位置
    findCityByName(&cities, "City2");

    // 查找半径内的城市
    findCitiesInRadius(&cities, 12.0, 22.0, 10.0);

    freeCityList(&cities);

    return 0;
}

