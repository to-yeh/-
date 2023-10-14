#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_CITIES 100

typedef struct {
    char name[50];
    double x;
    double y;
} City;

typedef struct {
    City cities[MAX_CITIES];
    int length;
} CityList;

void initCityList(CityList *list) {
    list->length = 0;
}

void addCity(CityList *list, const char *name, double x, double y) {
    if (list->length >= MAX_CITIES) {
        printf("�޷���ӳ��У�������Ϣ����\n");
        return;
    }

    City city;
    strncpy(city.name, name, sizeof(city.name));
    city.x = x;
    city.y = y;

    list->cities[list->length] = city;
    list->length++;
}

void findCityByName(CityList *list, const char *name) {
    for (int i = 0; i < list->length; i++) {
        if (strcmp(list->cities[i].name, name) == 0) {
            printf("������: %s, λ������: (%.2lf, %.2lf)\n", list->cities[i].name, list->cities[i].x, list->cities[i].y);
            return;
        }
    }
    printf("���� %s δ�ҵ�\n", name);
}

void findCitiesInRadius(CityList *list, double x, double y, double radius) {
    printf("�ڰ뾶 %.2lf �ڵĳ��У�\n", radius);
    for (int i = 0; i < list->length; i++) {
        double distance = sqrt(pow(list->cities[i].x - x, 2) + pow(list->cities[i].y - y, 2));
        if (distance <= radius) {
            printf("������: %s, λ������: (%.2lf, %.2lf), ����: %.2lf\n",
                list->cities[i].name, list->cities[i].x, list->cities[i].y, distance);
        }
    }
}

int main() {
    CityList cities;
    initCityList(&cities);

    addCity(&cities, "City1", 10.0, 20.0);
    addCity(&cities, "City2", 15.0, 25.0);
    addCity(&cities, "City3", 30.0, 40.0);

    // ���ҳ���λ��
    findCityByName(&cities, "City2");

    // ���Ұ뾶�ڵĳ���
    findCitiesInRadius(&cities, 12.0, 22.0, 10.0);

    return 0;
}

