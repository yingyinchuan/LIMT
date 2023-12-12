#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// 定义最大地点数
#define MAX_LOCATIONS 100

// 定义无穷大，表示两点之间没有直接路径
#define INFINITY INT_MAX

// 地点结构体
typedef struct {
    char name[50]; // 地点名称
    char description[200]; // 地点介绍
} Location;

// 地图结构体
typedef struct {
    int numLocations; // 地点数
    int distances[MAX_LOCATIONS][MAX_LOCATIONS]; // 距离矩阵
    Location locations[MAX_LOCATIONS]; // 地点数组
} Map;

// Dijkstra算法求最短路径
void dijkstra(Map *map, int start, int end, int *shortestDistances, int *predecessors) {
    int visited[MAX_LOCATIONS] = {0};

    // 初始化距离和前驱数组
    for (int i = 0; i < MAX_LOCATIONS; i++) {
        shortestDistances[i] = INFINITY;
        predecessors[i] = -1;
    }

    // 设置起点距离为0
    shortestDistances[start] = 0;

    // 找到最短路径
    for (int count = 0; count < map->numLocations - 1; count++) {
        int minDistance = INFINITY;
        int minIndex = -1;

        // 选择距离最短的点
        for (int v = 0; v < map->numLocations; v++) {
            if (!visited[v] && shortestDistances[v] < minDistance) {
                minDistance = shortestDistances[v];
                minIndex = v;
            }
        }

        // 标记选定点为已访问
        visited[minIndex] = 1;

        // 更新距离和前驱数组
        for (int v = 0; v < map->numLocations; v++) {
            if (!visited[v] && map->distances[minIndex][v] != INFINITY &&
                (shortestDistances[minIndex] + map->distances[minIndex][v] < shortestDistances[v])) {
                shortestDistances[v] = shortestDistances[minIndex] + map->distances[minIndex][v];
                predecessors[v] = minIndex;
            }
        }
    }
}

// 输出地点及其介绍
void printLocations(Map *map) {
    printf("所有地点及其介绍:\n");
    for (int i = 0; i < map->numLocations; i++) {
        printf("%s: %s\n", map->locations[i].name, map->locations[i].description);
    }
}

// 查询某一地点及其介绍
void queryLocation(Map *map, int index) {
    if (index >= 0 && index < map->numLocations) {
        printf("%s: %s\n", map->locations[index].name, map->locations[index].description);
    } else {
        printf("无效的地点索引\n");
    }
}

// 增加一个地点
void addLocation(Map *map, char *name, char *description) {
    if (map->numLocations < MAX_LOCATIONS) {
        strcpy(map->locations[map->numLocations].name, name);
        strcpy(map->locations[map->numLocations].description, description);
        map->numLocations++;
        printf("地点添加成功\n");
    } else {
        printf("地点数量已达到最大值\n");
    }
}

// 删除一个地点
void deleteLocation(Map *map, int index) {
    if (index >= 0 && index < map->numLocations) {
        // 删除地点及其关联的路径
        for (int i = 0; i < map->numLocations; i++) {
            map->distances[index][i] = INFINITY;
            map->distances[i][index] = INFINITY;
        }

        // 移动数组元素
        for (int i = index; i < map->numLocations - 1; i++) {
            map->locations[i] = map->locations[i + 1];
            for (int j = 0; j < map->numLocations; j++) {
                map->distances[j][i] = map->distances[j][i + 1];
            }
        }

        map->numLocations--;
        printf("地点删除成功\n");
    } else {
        printf("无效的地点索引\n");
    }
}

// 更新一个地点
void updateLocation(Map *map, int index, char *newName, char *newDescription) {
    if (index >= 0 && index < map->numLocations) {
        strcpy(map->locations[index].name, newName);
        strcpy(map->locations[index].description, newDescription);
        printf("地点更新成功\n");
    } else {
        printf("无效的地点索引\n");
    }
}

// 增加一条路径
void addPath(Map *map, int start, int end, int distance) {
    if (start >= 0 && start < map->numLocations && end >= 0 && end < map->numLocations) {
        map->distances[start][end] = distance;
        map->distances[end][start] = distance;
        printf("路径添加成功\n");
    } else {
        printf("无效的地点索引\n");
    }
}

// 删除一条路径
void deletePath(Map *map, int start, int end) {
    if (start >= 0 && start < map->numLocations && end >= 0 && end < map->numLocations) {
        map->distances[start][end] = INFINITY;
        map->distances[end][start] = INFINITY;
        printf("路径删除成功\n");
    } else {
        printf("无效的地点索引\n");
    }
}

// 更新一条路径
void updatePath(Map *map, int start, int end, int newDistance) {
    if (start >= 0 && start < map->numLocations && end >= 0 && end < map->numLocations) {
        map->distances[start][end] = newDistance;
        map->distances[end][start] = newDistance;
        printf("路径更新成功\n");
    } else {
        printf("无效的地点索引\n");
    }
}

// 查询某一地点到其他所有地点的最短路径
void shortestPathsFromLocation(Map *map, int start) {
    int shortestDistances[MAX_LOCATIONS];
    int predecessors[MAX_LOCATIONS];

    dijkstra(map, start, -1, shortestDistances, predecessors);

    printf("从%s到其他地点的最短路径:\n", map->locations[start].name);
    for (int i = 0; i < map->numLocations; i++) {
        if (i != start) {
            printf("%s 到 %s 的最短距离: %d\n", map->locations[start].name, map->locations[i].name, shortestDistances[i]);
        }
    }
}

// 查询某两个地点之间的最短路径
void shortestPathBetweenLocations(Map *map, int start, int end) {
    int shortestDistances[MAX_LOCATIONS];
    int predecessors[MAX_LOCATIONS];

    dijkstra(map, start, end, shortestDistances, predecessors);

    printf("%s 到 %s 的最短路径:\n", map->locations[start].name, map->locations[end].name);
    printf("最短距离: %d\n", shortestDistances[end]);

    // 构建路径
    printf("路径: ");
    int current = end;
    while (current != start) {
        printf("%s <- ", map->locations[current].name);
        current = predecessors[current];
    }
    printf("%s\n", map->locations[start].name);
}

int main() {
    Map myMap;
    myMap.numLocations = 0;

    // 初始化距离矩阵
    for (int i = 0; i < MAX_LOCATIONS; i++) {
        for (int j = 0; j < MAX_LOCATIONS; j++) {
            myMap.distances[i][j] = INFINITY;
        }
    }

    // 示例：增加一些地点和路径
    addLocation(&myMap, "青岛", "美丽的海滨城市");
    addLocation(&myMap, "北京", "中国的首都");
    addLocation(&myMap, "上海", "中国的金融中心");
    addLocation(&myMap, "广州", "中国的南大门");
    addPath(&myMap, 0, 1, 500); // 青岛到北京距离500
    addPath(&myMap, 0, 2, 600); // 青岛到上海距离600
    addPath(&myMap, 0, 3, 800); // 青岛到广州距离800

    // 示例：查询地点及其介绍
    printLocations(&myMap);

    // 示例：查询某一地点及其介绍
    queryLocation(&myMap, 1);

    // 示例：删除一个地点
    deleteLocation(&myMap, 2);
    printLocations(&myMap);

    // 示例：更新一个地点
    updateLocation(&myMap, 0, "青岛市", "美丽的海滨城市，啤酒之都");
    printLocations(&myMap);

    // 示例：查询某一地点到其他所有地点的最短路径
    shortestPathsFromLocation(&myMap, 0);

    // 示例：查询某两个地点之间的最短路径
    shortestPathBetweenLocations(&myMap, 0, 1);

    return 0;
}
