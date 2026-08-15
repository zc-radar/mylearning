#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 200
#define NAME_LEN 50
#define DATA_FILE "data/students.txt"

/*简单的student结构体声明*/
typedef struct {
  int id;
  char name[NAME_LEN];
  float score;
} Student;

/* 函数声明 */
void print_menu(void);
int load_students(Student arr[], int max_count);
int save_students(Student arr[], int count);

void add_student(Student arr[], int* count);
void list_students(Student arr[], int count);
void find_student(Student arr[], int count);
void delete_student(Student arr[], int* count);
void update_student(Student arr[], int count);
void stats_students(Student arr[], int count);

int find_index_by_id(Student arr[], int count, int id);

int main(void) {
  Student students[MAX_STUDENTS];
  int count = 0;
  int choice = 0;

  /* 启动时加载数据 */
  count = load_students(students, MAX_STUDENTS);
  printf("已加载 %d 条学生记录。\n", count);

  while (1) {
    print_menu();
    printf("请输入选项: ");
    if (scanf("%d", &choice) != 1) {
      printf("输入无效，程序退出。\n");
      break;
    }

    switch (choice) {
      case 1:
        add_student(students, &count);
        break;
      case 2:
        list_students(students, count);
        break;
      case 3:
        find_student(students, count);
        break;
      case 4:
        update_student(students, count);
        break;
      case 5:
        delete_student(students, &count);
        break;
      case 6:
        stats_students(students, count);
        break;
      case 7:
        if (save_students(students, count) == 0) {
          printf("保存成功，退出程序。\n");
        } else {
          printf("保存失败，但仍退出程序。\n");
        }
        return 0;
      default:
        printf("无效选项，请重试。\n");
        break;
    }
  }

  return 0;
}

void print_menu(void) {
  printf("\n========== 学生成绩管理系统 ==========\n");
  printf("1. 添加学生\n");
  printf("2. 显示全部学生\n");
  printf("3. 按学号查找\n");
  printf("4. 修改学生成绩\n");
  printf("5. 删除学生\n");
  printf("6. 统计信息\n");
  printf("7. 保存并退出\n");
  printf("=====================================\n");
}

int load_students(Student arr[], int max_count) {
  FILE* fp = fopen(DATA_FILE, "r");
  int count = 0;

  if (fp == NULL) {
    /* 首次运行没有文件是正常的 */
    return 0;
  }

  while (count < max_count && fscanf(fp, "%d %49s %f", &arr[count].id,
                                     arr[count].name, &arr[count].score) == 3) {
    count++;
  }

  fclose(fp);
  return count;
}

int save_students(Student arr[], int count) {
  FILE* fp = fopen(DATA_FILE, "w");
  int i;

  if (fp == NULL) {
    perror("fopen");
    return -1;
  }

  for (i = 0; i < count; i++) {
    fprintf(fp, "%d %s %.2f\n", arr[i].id, arr[i].name, arr[i].score);
  }

  fclose(fp);
  return 0;
}

int find_index_by_id(Student arr[], int count, int id) {
  int i;
  for (i = 0; i < count; i++) {
    if (arr[i].id == id) {
      return i;
    }
  }
  return -1;
}

void add_student(Student arr[], int* count) {
  Student s;
  int idx;

  if (*count >= MAX_STUDENTS) {
    printf("学生数量已达上限，无法添加。\n");
    return;
  }

  printf("输入学号: ");
  scanf("%d", &s.id);

  idx = find_index_by_id(arr, *count, s.id);
  if (idx != -1) {
    printf("学号已存在，添加失败。\n");
    return;
  }

  printf("输入姓名(无空格): ");
  scanf("%49s", s.name);

  printf("输入成绩: ");
  scanf("%f", &s.score);

  arr[*count] = s;
  (*count)++;

  printf("添加成功。\n");
}

void list_students(Student arr[], int count) {
  int i;

  if (count == 0) {
    printf("暂无学生记录。\n");
    return;
  }

  printf("\n%-10s %-20s %-10s\n", "学号", "姓名", "成绩");
  printf("----------------------------------------\n");

  for (i = 0; i < count; i++) {
    printf("%-10d %-20s %-10.2f\n", arr[i].id, arr[i].name, arr[i].score);
  }
}

void find_student(Student arr[], int count) {
  int id, idx;

  if (count == 0) {
    printf("暂无学生记录。\n");
    return;
  }

  printf("输入要查找的学号: ");
  scanf("%d", &id);

  idx = find_index_by_id(arr, count, id);
  if (idx == -1) {
    printf("未找到该学号。\n");
    return;
  }

  printf("找到: 学号=%d, 姓名=%s, 成绩=%.2f\n", arr[idx].id, arr[idx].name,
         arr[idx].score);
}

void update_student(Student arr[], int count) {
  int id, idx;
  float new_score;

  if (count == 0) {
    printf("暂无学生记录。\n");
    return;
  }

  printf("输入要修改成绩的学号: ");
  scanf("%d", &id);

  idx = find_index_by_id(arr, count, id);
  if (idx == -1) {
    printf("未找到该学号。\n");
    return;
  }

  printf("当前成绩: %.2f\n", arr[idx].score);
  printf("输入新成绩: ");
  scanf("%f", &new_score);

  arr[idx].score = new_score;
  printf("修改成功。\n");
}

void delete_student(Student arr[], int* count) {
  int id, idx, i;

  if (*count == 0) {
    printf("暂无学生记录。\n");
    return;
  }

  printf("输入要删除的学号: ");
  scanf("%d", &id);

  idx = find_index_by_id(arr, *count, id);
  if (idx == -1) {
    printf("未找到该学号。\n");
    return;
  }

  for (i = idx; i < *count - 1; i++) {
    arr[i] = arr[i + 1];
  }

  (*count)--;
  printf("删除成功。\n");
}

void stats_students(Student arr[], int count) {
  int i;
  float sum = 0.0f;
  float max_score, min_score, avg;
  int max_idx = 0, min_idx = 0;

  if (count == 0) {
    printf("暂无学生记录。\n");
    return;
  }

  max_score = arr[0].score;
  min_score = arr[0].score;

  for (i = 0; i < count; i++) {
    sum += arr[i].score;

    if (arr[i].score > max_score) {
      max_score = arr[i].score;
      max_idx = i;
    }

    if (arr[i].score < min_score) {
      min_score = arr[i].score;
      min_idx = i;
    }
  }

  avg = sum / count;

  printf("总人数: %d\n", count);
  printf("平均分: %.2f\n", avg);
  printf("最高分: %.2f (学号=%d, 姓名=%s)\n", arr[max_idx].score,
         arr[max_idx].id, arr[max_idx].name);
  printf("最低分: %.2f (学号=%d, 姓名=%s)\n", arr[min_idx].score,
         arr[min_idx].id, arr[min_idx].name);
}