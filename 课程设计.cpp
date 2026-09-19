#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define FILENAME "student.txt"
#define LOGFILE  "log.txt"
#define LENGTH 50

typedef struct Student {
 char college[LENGTH];
 char major[LENGTH];
 char grade[LENGTH];
 char cls[LENGTH];
 char id[LENGTH];
 char name[LENGTH];
 char age[LENGTH];
 char sex[LENGTH];
 char birth[LENGTH];
 char addr[LENGTH];
 char tel[LENGTH];
 char email[LENGTH];
 char dorm[LENGTH];
 char party[LENGTH];
 struct Student *next;
} Student;
Student *StudentList = NULL;
void writeLog(Student *delStu)
{
    FILE *fp = fopen(LOGFILE, "a");
    if (!fp)
    {
        cout << "日志文件打开失败！" << endl;
        return;
    }
    fprintf(fp, "【删除学生记录】\n");
    fprintf(fp, "学院：%s  专业：%s  年级：%s  班级：%s\n",
            delStu->college, delStu->major, delStu->grade, delStu->cls);
    fprintf(fp, "学号：%s  姓名：%s  年龄：%s  性别：%s\n",
            delStu->id, delStu->name, delStu->age, delStu->sex);
    fprintf(fp, "出生年月：%s  住址：%s  电话：%s  邮箱：%s\n",
            delStu->birth, delStu->addr, delStu->tel, delStu->email);
    fprintf(fp, "宿舍：%s  政治面貌：%s\n", delStu->dorm, delStu->party);
    fprintf(fp, "---------------------------------------------\n");

    fclose(fp);
    cout << "该学生信息已写入删除日志！" << endl;
}
Student *createNode() {
 Student *p = new Student;
 p->next = NULL;
 return p;
}
void menu() {
 cout << "=====学生信息管理系统=====" << endl;
 cout << "1. 新增学生" << endl;
 cout << "2. 浏览学生" << endl;
 cout << "3. 按学号查询" << endl;
 cout << "4. 按姓名查询" << endl;
 cout << "5. 删除学生" << endl;
 cout << "6. 修改学生信息" << endl;
 cout << "7. 按学号排序" << endl;
 cout << "8. 按年龄排序" << endl;
 cout << "9. 筛选功能" << endl;
 cout << "0. 保存并退出" << endl;
 cout << "请选择操作：";
 }
void addStudent() {
 Student *s = createNode();
 cout<<"正在添加学生信息，请输入以下信息"<<endl;
 cout << "学院：";
 cin >> s->college;
 cout << "专业：";
 cin >> s->major;
 cout << "年级：";
 cin >> s->grade;
 cout << "班级：";
 cin >> s->cls;
 cout << "学号：";
 cin >> s->id;
 cout << "姓名：";
 cin >> s->name;
 cout << "年龄：";
 cin >> s->age;
 cout << "性别：";
 cin >> s->sex;
 cout << "出生年月：";
 cin >> s->birth;
 cout << "住址：";
 cin >> s->addr;
 cout << "电话：";
 cin >> s->tel;
 cout << "邮箱：";
 cin >> s->email;
 cout << "宿舍：";
 cin >> s->dorm;
 cout << "政治面貌：";
 cin >> s->party;
 s->next = NULL;
 if (StudentList == NULL) {
 StudentList = s;
 } else {
 Student *p = StudentList;
 while (p->next)
 p = p->next;
 p->next = s;
 }
 cout << "添加成功"<<endl;
}

void showAll() {
 cout << "姓名\t学号\t\t性别\t年龄\t学院\t\t班级\t专业"<<endl;
 Student *p = StudentList;
 while (p) {
 cout << p->name << "\t" << p->id << "\t" <<p->sex<<"\t"<< p->age << "\t" << p->college<<"\t"<<p->cls<<"\t"<<p->major <<endl;
 p = p->next;
 }
 cout << "=====学生信息非完整信息=====" << endl;
}
void searchId() {
 char id[LENGTH];
 cout << "输入查询学号：";
 cin >> id;
 Student *p = StudentList;
 bool find = false;
 while (p) {
 if (strcmp(p->id, id) == 0) {
 cout << "=====学生完整信息=====" << endl;
 cout << "学院：" << p->college << endl;
 cout << "专业：" << p->major << endl;
 cout << "年级：" << p->grade << endl;
 cout << "班级：" << p->cls << endl;
 cout << "学号：" << p->id << endl;
 cout << "姓名：" << p->name << endl;
 cout << "年龄：" << p->age << endl;
 cout << "性别：" << p->sex << endl;
 cout << "出生年月：" << p->birth << endl;
 cout << "住址：" << p->addr << endl;
 cout << "电话：" << p->tel << endl;
 cout << "邮箱：" << p->email << endl;
 cout << "宿舍：" << p->dorm << endl;
 cout << "政治面貌：" << p->party << endl;
 find = true;
 break;
 }
 p = p->next;
 }
 if (!find)
 cout << "未查询到学生，请检查学号输入是否正确"<<endl;
}
void searchName() {
 char name[LENGTH];
 cout << "输入查询姓名：";
 cin >> name;
 Student *p = StudentList;
 bool find = false;
 while (p) {
 if (strcmp(p->name, name) == 0) {
 cout << "=====学生完整信息=====" << endl;
 cout << "学院：" << p->college << endl;
 cout << "专业：" << p->major << endl;
 cout << "年级：" << p->grade << endl;
 cout << "班级：" << p->cls << endl;
 cout << "学号：" << p->id << endl;
 cout << "姓名：" << p->name << endl;
 cout << "年龄：" << p->age << endl;
 cout << "性别：" << p->sex << endl;
 cout << "出生年月：" << p->birth << endl;
 cout << "住址：" << p->addr << endl;
 cout << "电话：" << p->tel << endl;
 cout << "邮箱：" << p->email << endl;
 cout << "宿舍：" << p->dorm << endl;
 cout << "政治面貌：" << p->party << endl;
 find = true;
 break;
 }
 p = p->next;
 }
 if (!find)
 cout << "未查询到学生，请检查姓名输入是否正确"<<endl;
}
void delStudent()
{
 char id[LENGTH];
 cout << "输入删除学号：";
 cin >> id;
 Student* p = StudentList;
 Student* pre = NULL;
 while (p && strcmp(p->id, id) != 0)
 {
 pre = p;
 p = p->next;
 }
 if (!p)
 {
 cout << "无该学生，请检查学号输入是否正确"<<endl;
 return;
 }
    writeLog(p);
 if (pre == NULL)
 StudentList = p->next;
 else
 pre->next = p->next;
 delete p;
 cout << "删除成功"<<endl;
}
void modifyStudent()
 {
 char id[LENGTH];
 cout << "请输入要修改的学生学号："<<endl;
 cin >> id;
 Student* p = StudentList;
 while (p && strcmp(p->id, id) != 0)
 {
 p = p->next;
 }
 if (!p)
 {
 cout << "无该学生，请检查学号输入是否正确"<<endl;
 return;
 }
 int choice;
cout << "1.学院" << endl;
cout << "2.专业" << endl;
cout << "3.年级" << endl;
cout << "4.班级" << endl;
cout << "5.学号" << endl;
cout << "6.姓名" << endl;
cout << "7.年龄" << endl;
cout << "8.性别" << endl;
cout << "9.出生年月" << endl;
cout << "10.住址" << endl;
cout << "11.电话" << endl;
cout << "12.邮箱" << endl;
cout << "13.宿舍" << endl;
cout << "14.政治面貌" << endl;
 cout << "请输入要修改的选项："<<endl;
 cin >> choice;
 switch (choice)
 {
 case 1: cout << "请输入新学院：";
 cin >> p->college; break;
 case 2: cout << "请输入新专业：";
 cin >> p->major; break;
 case 3: cout << "请输入新年级：";
 cin >> p->grade; break;
 case 4: cout << "请输入新班级：";
 cin >> p->cls; break;
 case 5: cout << "请输入新学号：";
 cin >> p->id; break;
 case 6: cout << "请输入新姓名：";
 cin >> p->name; break;
 case 7: cout << "请输入新年龄：";
 cin >> p->age; break;
 case 8: cout << "请输入新性别：";
 cin >> p->sex; break;
 case 9: cout << "请输入新出生年月：";
 cin >> p->birth; break;
 case 10: cout << "请输入新住址：";
 cin >> p->addr; break;
 case 11: cout << "请输入新电话：";
 cin >> p->tel; break;
 case 12: cout << "请输入新邮箱：";
 cin >> p->email; break;
 case 13: cout << "请输入新宿舍：";
 cin >> p->dorm; break;
 case 14: cout << "请输入新政治面貌：";
 cin >> p->party; break;
 default: cout << "选项无效！\n"; return;
 }
 cout << "对应信息修改成功！"<<endl;
 }
void sortId()
{
    if (!StudentList || !StudentList->next)
    {
        cout << "无需排序"<<endl;
        return;
    }
    Student *p, *q;
    char t[LENGTH]; 
    for (p = StudentList; p->next; p = p->next)
    {
        for (q = StudentList; q->next; q = q->next)
        {
            if (strcmp(q->id, q->next->id) > 0)
            {

                strcpy(t, q->college); strcpy(q->college, q->next->college); strcpy(q->next->college, t);
                strcpy(t, q->major);   strcpy(q->major, q->next->major);   strcpy(q->next->major, t);
                strcpy(t, q->grade);   strcpy(q->grade, q->next->grade);   strcpy(q->next->grade, t);
                strcpy(t, q->cls);     strcpy(q->cls, q->next->cls);     strcpy(q->next->cls, t);
                strcpy(t, q->id);      strcpy(q->id, q->next->id);      strcpy(q->next->id, t);
                strcpy(t, q->name);    strcpy(q->name, q->next->name);    strcpy(q->next->name, t);
                strcpy(t, q->age);     strcpy(q->age, q->next->age);     strcpy(q->next->age, t);
                strcpy(t, q->sex);     strcpy(q->sex, q->next->sex);     strcpy(q->next->sex, t);
                strcpy(t, q->birth);   strcpy(q->birth, q->next->birth); strcpy(q->next->birth, t);
                strcpy(t, q->addr);    strcpy(q->addr, q->next->addr);   strcpy(q->next->addr, t);
                strcpy(t, q->tel);     strcpy(q->tel, q->next->tel);     strcpy(q->next->tel, t);
                strcpy(t, q->email);   strcpy(q->email, q->next->email); strcpy(q->next->email, t);
                strcpy(t, q->dorm);    strcpy(q->dorm, q->next->dorm);   strcpy(q->next->dorm, t);
                strcpy(t, q->party);   strcpy(q->party, q->next->party); strcpy(q->next->party, t);
            }
        }
    }
    cout << "已按学号排序"<<endl;
}
void sortAge()
{
    if (!StudentList || !StudentList->next)
    {
        cout << "无需排序"<<endl;
        return;
    }
    Student *p, *q;
    char t[LENGTH];
    for (p = StudentList; p->next; p = p->next)
    {
        for (q = StudentList; q->next; q = q->next)
        {
            if (strcmp(q->age, q->next->age) > 0)
            {
                strcpy(t, q->college); strcpy(q->college, q->next->college); strcpy(q->next->college, t);
                strcpy(t, q->major);   strcpy(q->major, q->next->major);   strcpy(q->next->major, t);
                strcpy(t, q->grade);   strcpy(q->grade, q->next->grade);   strcpy(q->next->grade, t);
                strcpy(t, q->cls);     strcpy(q->cls, q->next->cls);     strcpy(q->next->cls, t);
                strcpy(t, q->id);      strcpy(q->id, q->next->id);      strcpy(q->next->id, t);
                strcpy(t, q->name);    strcpy(q->name, q->next->name);    strcpy(q->next->name, t);
                strcpy(t, q->age);     strcpy(q->age, q->next->age);     strcpy(q->next->age, t);
                strcpy(t, q->sex);     strcpy(q->sex, q->next->sex);     strcpy(q->next->sex, t);
                strcpy(t, q->birth);   strcpy(q->birth, q->next->birth); strcpy(q->next->birth, t);
                strcpy(t, q->addr);    strcpy(q->addr, q->next->addr);   strcpy(q->next->addr, t);
                strcpy(t, q->tel);     strcpy(q->tel, q->next->tel);     strcpy(q->next->tel, t);
                strcpy(t, q->email);   strcpy(q->email, q->next->email); strcpy(q->next->email, t);
                strcpy(t, q->dorm);    strcpy(q->dorm, q->next->dorm);   strcpy(q->next->dorm, t);
                strcpy(t, q->party);   strcpy(q->party, q->next->party); strcpy(q->next->party, t);
            }
        }
    }
    cout << "已按年龄排序"<<endl;
}
/*void sortAge()
{

 if (!StudentList || !StudentList->next)
 {
 cout << "无需排序"<<endl;
 return;
 }
 Student *p, *q;
 Student temp;
 for (p = StudentList; p->next; p = p->next)
 {
 for (q = StudentList; q->next; q = q->next)
 {
 if (strcmp(q->age, q->next->age) > 0)
 {
 temp = *q;
 *q = *(q->next);
 *(q->next) = temp;
 }
 }
 }
 cout << "已按年龄排序"<<endl;
}*/
void selectSex()
 {
 if (!StudentList || !StudentList->next)
 {
 cout << "无需筛选"<<endl;
 return;
 }
 char instant[LENGTH];
 cout << "请输入要筛选的性别：";
 cin >> instant;
 cout << "=====筛选结果=====" << endl;
 cout << "姓名\t学号\t\t性别\t年龄\t学院\t\t班级\t专业"<<endl;
 Student* p = StudentList;
 bool find = false;
 while (p != NULL)
 {
 if (strcmp(p->sex,instant) == 0)
 {
 cout << p->name << "\t" << p->id << "\t" <<p->sex<<"\t"<< p->age << "\t" << p->college<<"\t"<<p->cls<<"\t"<<p->major <<endl;
 find = true;
 }
 p = p->next;
 }
 if (!find)
 {
 cout << "未找到对应性别学生！" << endl;
 }
 }
void selectCls()
 {
 if (!StudentList || !StudentList->next)
 {
 cout << "无需筛选"<<endl;
 return;
 }
 char instant[LENGTH];
 cout << "请输入要筛选的班级：";
 cin >> instant;
 cout << "=====筛选结果=====" << endl;
 cout << "姓名\t学号\t\t性别\t年龄\t学院\t\t班级\t专业"<<endl;
 Student* p = StudentList;
 bool find = false;
 while (p != NULL)
 {
 if (strcmp(p->cls,instant) == 0)
 {
 cout << p->name << "\t" << p->id << "\t" <<p->sex<<"\t"<< p->age << "\t" << p->college<<"\t"<<p->cls<<"\t"<<p->major<< endl;
 find = true;
 }
 p = p->next;
 }
 if (!find)
 {
 cout << "未找到对应班级学生！" << endl;
 }
 }
void selectCollege()
 {
 if (!StudentList || !StudentList->next)
 {
 cout << "无需筛选"<<endl;
 return;
 }
 char instant[LENGTH];
 cout << "请输入要筛选的学院：";
 cin >> instant;
 cout << "=====筛选结果=====" << endl;
 cout << "姓名\t学号\t\t性别\t年龄\t学院\t\t班级\t专业"<<endl;
 Student* p = StudentList;
 bool find = false;
 while (p != NULL)
 {
 if (strcmp(p->college,instant) == 0)
 {
 cout << p->name << "\t" << p->id << "\t" <<p->sex<<"\t"<< p->age << "\t" << p->college<<"\t"<<p->cls<<"\t"<<p->major<< endl;
 find = true;
 }
 p = p->next;
 }
 if (!find)
 {
 cout << "未找到对应学院学生！" << endl;
 }
 }
void selectMajor()
 {
 if (!StudentList || !StudentList->next)
 {
 cout << "无需筛选"<<endl;
 return;
 }
 char instant[LENGTH];
 cout << "请输入要筛选的专业：";
 cin >> instant;
 cout << "=====筛选结果=====" << endl;
 cout << "姓名\t学号\t\t性别\t年龄\t学院\t\t班级\t专业"<<endl;
 Student* p = StudentList;
 bool find = false;
 while (p != NULL)
 {
 if (strcmp(p->major,instant) == 0)
 {
 cout << p->name << "\t" << p->id << "\t" <<p->sex<<"\t"<< p->age << "\t" << p->college<<"\t"<<p->cls<<"\t"<<p->major<< endl;
 find = true;
 }
 p = p->next;
 }
 if (!find)
 {
 cout << "未找到对应专业学生！" << endl;
 }
 }
void selectParty()
 {
 if (!StudentList || !StudentList->next)
 {
 cout << "无需筛选"<<endl;
 return;
 }
 char instant[LENGTH];
 cout << "请输入要筛选的政治面貌：";
 cin >> instant;
 cout << "=====筛选结果=====" << endl;
 cout << "姓名\t学号\t\t性别\t年龄\t学院\t\t班级\t政治面貌"<<endl;
 Student* p = StudentList;
 bool find = false;
 while (p != NULL)
 {
 if (strcmp(p->party,instant) == 0)
 {
 cout << p->name << "\t" << p->id << "\t" <<p->sex<<"\t"<< p->age << "\t" << p->college<<"\t"<<p->cls<<"\t"<<p->party<<endl;
 find = true;
 }
 p = p->next;
 }
 if (!find)
 {
 cout << "未找到对应政治面貌的学生！" << endl;
 }
 }
void selectGrade()
 {
 if (!StudentList || !StudentList->next)
 {
 cout << "无需筛选"<<endl;
 return;
 }
 char instant[LENGTH];
 cout << "请输入要筛选的年级：";
 cin >> instant;
 cout << "=====筛选结果=====" << endl;
 cout << "姓名\t学号\t\t性别\t年级\t学院\t\t班级\t专业"<<endl;
 Student* p = StudentList;
 bool find = false;
 while (p != NULL)
 {
 if (strcmp(p->grade,instant) == 0)
 {
 cout << p->name << "\t" << p->id << "\t" <<p->sex<<"\t"<< p->grade<< "\t" << p->college<<"\t"<<p->cls<<"\t"<<p->major<< endl;
 find = true;
 }
 p = p->next;
 }
 if (!find)
 {
 cout << "未找到对应年级学生！" << endl;
 }
 }
void readFile() {
     FILE* fp = fopen(FILENAME, "r");
     if (!fp) {
         cout << "暂无历史数据文件" << endl;
         return;
     }
	 //删原链表
     Student *p = StudentList, *q;
     while (p) {
         q = p->next;
         delete p;
         p = q;
     }
     StudentList = NULL;
     while (1) {
         Student* s = createNode();
         int ret = fscanf(fp, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s",
                          s->college, s->major, s->grade, s->cls, s->id, s->name,
                          s->age, s->sex, s->birth, s->addr, s->tel, s->email,
                          s->dorm, s->party);
         if (ret == EOF) {
             delete s;
             break;
         }
         if (StudentList == NULL)
             StudentList = s;
         else {
             Student* tmp = StudentList;
             while (tmp->next) tmp = tmp->next;
             tmp->next = s;
         }
     }
     fclose(fp);
     cout << "历史数据读取完成" << endl;
 }

void saveFile()
 {
 FILE* fp = fopen(FILENAME, "w");
 if (!fp) return;
 Student* p = StudentList;
 while (p)
 {
 fprintf(fp, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s\n",
 p->college, p->major, p->grade, p->cls, p->id, p->name,
 p->age, p->sex, p->birth, p->addr, p->tel, p->email, p->dorm, p->party);
 p = p->next;
 }
 fclose(fp);
 }
 void selectMenu()
 {
 int op;
 while (1)
 {
 cout << "\n=====筛选菜单=====" << endl;
 cout << "1.按性别筛选" << endl;
 cout << "2.按班级筛选" << endl;
 cout << "3.按学院筛选" << endl;
 cout << "4.按专业筛选" << endl;
 cout << "5.按政治面貌筛选" << endl;
 cout << "6.按年级筛选" << endl;
 cout << "0.返回上一级" << endl;
 cout << "请选择：";
 cin >> op;
 switch (op)
 {
 case 1: selectSex(); break;
 case 2: selectCls(); break;
 case 3: selectCollege(); break;
 case 4: selectMajor(); break;
 case 5: selectParty(); break;
 case 6: selectGrade(); break;
 case 0: return;
 default: cout << "输入错误！" << endl; break;
 }
 }
 }

int main() {
	readFile();
int choice;
 while (1)
 {
 menu();
 cin >> choice;
 switch (choice)
 {
 case 1: addStudent(); break;
 case 2: showAll(); break;
 case 3: searchId(); break;
 case 4: searchName(); break;
 case 5: delStudent(); break;
 case 6: modifyStudent(); break;
 case 7: sortId(); break;
 case 8: sortAge(); break;
 case 9: selectMenu(); break;
 case 0:saveFile(); cout << "数据已保存，程序退出！" << endl;
 return 0;
 default:cout << "输入错误，请重新选择！" << endl;
 break;
 }
 cout << "-------------------------" << endl;
 }
 return 0;

}

