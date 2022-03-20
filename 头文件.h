#ifndef _x_h_
#define _x_h_

void title();
void run();

typedef struct node {
	int num;
	struct node* next;
}list,*List;

List creat_plist();//创建新链表
void add_list(int number, List begin, List add);//加入新节点到链表
void add_number(List add);//新节点数据加入
void out_list(List head);//输出打印链表数据
int count_list(List head);//链表数据计数
void oppolist(List headnext, List head);//翻转链表
void mid(List head);//打印中间节点值
int judelist(List Head);//判断传入链表是否为空
void iscycle(List head);//判断是否成环
void del_list(List head);//删除链表中某节点
void del_alllist(List Head);//删除全部链表

void title()//打印功能菜单
{
	printf("\t*********************系统功能菜单***************\n");
	printf("\t------------------------------------------------\n");
	printf("\t***********************************************\n");
	printf("\t*  a.创建新链表       * *    b.插入新节点     *\n");
	printf("\t***********************************************\n");
	printf("\t*  c.输出链表         * *    d.将链表反向     *\n");
	printf("\t***********************************************\n");
	printf("\t*  e.找到单链表中点   * *    f.判断是否成环   *\n");
	printf("\t***********************************************\n");
	printf("\t*                g.删除目标节点               *\n");
	printf("\t***********************************************\n");
	printf("\t*                h.删除链表并退出系统         *\n");
	printf("\t***********************************************\n");
}
void run() {
	int judenum;
	char b[10];
	char a;
	List Head = NULL;
	do
	{
		system("cls");
		title();
		printf("请在a到i中选择：\n");
		while (1)  // 循环检查输入的值是否正确
		{
			scanf("%s", &b);
			if (b[0] > 'i' || b[0] < 'a') {
				printf("请输入正确字母（a~i）\n");
				continue;
			}
			a = b[0]+b[1];//排除字符串输入异常
			if (a > 'k' || a < 'a')
			{
				printf("请输入正确字母（a~i）\n");
				continue;    // 输入不正确，重新输入
			}
			else
			{
				break; // 输入正确，退出循环
			}
		}
		switch (a)
		{
		case 'a':
			system("cls");
			printf("\t\t----------          创建新链表          ---------\n");
			Head = creat_plist();
			if (Head==NULL) {
				printf("请先释放内存\n");
			}
			else {
				printf("创建链表成功\n");
			}
			system("pause");
			break;
		case 'b':
			system("cls");
			printf("\t\t----------          插入新节点          ---------\n");
			if (Head==NULL) {
				printf("请先创建链表\n");
				system("pause");
				break;
			}
			List add = creat_plist();
			add_number(add);//创建节点
			out_list(Head);
			printf("请输入你要插入的位置：\n");
			printf("ps:插入末尾，请输入：0\n");
			printf("数字范围：0~%d\n", count_list(Head));
			int aim;
			scanf("%d", &aim);
			if (aim<0 || aim>count_list(Head)) {
				printf("你输入的值有错误");
				system("pause");
				break;
			}
			aim--;
			add_list(aim,Head, add);//加入节点
			system("pause");
			break;
		case 'c':
			system("cls");
			printf("\t\t----------         输出链表          ---------\n");
			judenum=judelist(Head);
			if (judenum == 0)break;
			out_list(Head);
			system("pause");
			break;
		case 'd':
			system("cls");
			printf("----------          将链表反向           ----------\n");
			judenum = judelist(Head);
			if (judenum == 0)break;
			oppolist(Head->next,Head);
			system("pause");
			break;
		case 'e':
			system("cls");
			printf("\t\t----------          找到单链表中点          ---------\n");
			judenum = judelist(Head);
			if (judenum == 0)break;
			mid(Head->next);
			system("pause");
			break;
		case 'f':
			system("cls");
			printf("\t\t----------           判断是否成环          ---------\n");
			judenum=judelist(Head);
			if (judenum == 0)break;
			iscycle(Head);
			system("pause");
			break;

		case 'g':
			system("cls");
			printf("\t\t----------           删除节点取值          ---------\n");
			out_list(Head);
			judenum = judelist(Head);
			if (judenum == 0)break;
			del_list(Head);
			printf("删除成功");
			system("pause");
			break;
		case 'h':
			system("cls");
			printf("\t\t----------         删除链表           ---------\n");
			judenum = judelist(Head);
			if (judenum == 0)break;
			del_alllist(Head);
			printf("删除成功！！\n");
			system("pause");
			return 0;
		}
	} while (a != 0);
}
List creat_plist() {
	List newlist=(List*)malloc(sizeof(list));
	newlist->next = NULL;
	return newlist;
}
void add_list(int number,List begin, List add) {
	if(number==-1){
		while (begin->next)
		begin = begin->next;
	}
	else {
		for (number; number; number--)
			begin = begin->next;
	}
	add->next=begin->next ;
	begin->next = add;
}
void add_number(List add) {
	printf("请输入新节点的数据（必须为数字）\n");
	int number;
	scanf("%d", &number);
	add->num = number;
}
void out_list(List head) {
	while (head->next) {
		printf("%d->", head->next->num);
		head = head->next;
	}
	printf("\n");
}
int count_list(List head) {//对链表数据计数
	int count = 0;
	while (head->next) {
		count++;
		head = head->next;
	}
	return count;
}
void oppolist(List headnext,List head) {//翻转链表:把当前的指向上一个，然后变量往后挪
	List  fornt= NULL;
		List mid = headnext;
		while (mid) {
			List behide =mid->next;//下一个节点不让其丢失
			mid->next = fornt;
			fornt = mid;
			mid = behide;
		}
		head->next = fornt;
		printf("翻转后：\n");
		out_list(head);
}
void mid(List head) {
	if (head == NULL) {
		printf("请先创建链表\n");
		return;
	}
	List slow = head;
	List fast = head;
	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}
	printf("中间节点的值为%d\n", slow->num);
}
int judelist(List Head) {//通过a的值判断有无链表建立
	int a = 1;
	if (Head == NULL || Head->next == NULL) {
		printf("请先创建链表或添加链表\n");
		system("pause");
		a = 0;
		return a;
	}
}
void iscycle(List head) {//判断是否成环
	List slow = head;
	List fast = head->next;
	while (slow != fast) {
		if (fast == NULL || fast->next == NULL) {
			printf("该链表没有成环\n");
			return;
		}
		slow = slow->next;
		fast = fast->next->next;
	}
	printf("该链表成环\n");
	return;
}
void del_list(List head) {//删除指定节点
	int delnum;
	printf("请输入你需要删除节的点值\n");
	scanf("%d", &delnum);
	for (List L=head; L->next; L = L->next) {
		if (L->next->num == delnum) {
			if (L->next->next == NULL) {
				free(L->next);
				L->next = NULL;
				break;
			}
			else {
				List nextlist = L->next->next;
				free(L->next);
				L->next = nextlist;
			}
		}
	}
}
void del_alllist(List Head) {//删除全部链表
	while(Head)
	{
		List nexthead = Head->next;
		free(Head);
		Head = nexthead;
	}
}
#endif
