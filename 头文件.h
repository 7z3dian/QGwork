#ifndef _x_h_
#define _x_h_

void title();
void run();

typedef struct node {
	int num;
	struct node* next;
}list,*List;

List creat_plist();//����������
void add_list(int number, List begin, List add);//�����½ڵ㵽����
void add_number(List add);//�½ڵ����ݼ���
void out_list(List head);//�����ӡ��������
int count_list(List head);//�������ݼ���
void oppolist(List headnext, List head);//��ת����
void mid(List head);//��ӡ�м�ڵ�ֵ
int judelist(List Head);//�жϴ��������Ƿ�Ϊ��
void iscycle(List head);//�ж��Ƿ�ɻ�
void del_list(List head);//ɾ��������ĳ�ڵ�
void del_alllist(List Head);//ɾ��ȫ������

void title()//��ӡ���ܲ˵�
{
	printf("\t*********************ϵͳ���ܲ˵�***************\n");
	printf("\t------------------------------------------------\n");
	printf("\t***********************************************\n");
	printf("\t*  a.����������       * *    b.�����½ڵ�     *\n");
	printf("\t***********************************************\n");
	printf("\t*  c.�������         * *    d.��������     *\n");
	printf("\t***********************************************\n");
	printf("\t*  e.�ҵ��������е�   * *    f.�ж��Ƿ�ɻ�   *\n");
	printf("\t***********************************************\n");
	printf("\t*                g.ɾ��Ŀ��ڵ�               *\n");
	printf("\t***********************************************\n");
	printf("\t*                h.ɾ�������˳�ϵͳ         *\n");
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
		printf("����a��i��ѡ��\n");
		while (1)  // ѭ����������ֵ�Ƿ���ȷ
		{
			scanf("%s", &b);
			if (b[0] > 'i' || b[0] < 'a') {
				printf("��������ȷ��ĸ��a~i��\n");
				continue;
			}
			a = b[0]+b[1];//�ų��ַ��������쳣
			if (a > 'k' || a < 'a')
			{
				printf("��������ȷ��ĸ��a~i��\n");
				continue;    // ���벻��ȷ����������
			}
			else
			{
				break; // ������ȷ���˳�ѭ��
			}
		}
		switch (a)
		{
		case 'a':
			system("cls");
			printf("\t\t----------          ����������          ---------\n");
			Head = creat_plist();
			if (Head==NULL) {
				printf("�����ͷ��ڴ�\n");
			}
			else {
				printf("��������ɹ�\n");
			}
			system("pause");
			break;
		case 'b':
			system("cls");
			printf("\t\t----------          �����½ڵ�          ---------\n");
			if (Head==NULL) {
				printf("���ȴ�������\n");
				system("pause");
				break;
			}
			List add = creat_plist();
			add_number(add);//�����ڵ�
			out_list(Head);
			printf("��������Ҫ�����λ�ã�\n");
			printf("ps:����ĩβ�������룺0\n");
			printf("���ַ�Χ��0~%d\n", count_list(Head));
			int aim;
			scanf("%d", &aim);
			if (aim<0 || aim>count_list(Head)) {
				printf("�������ֵ�д���");
				system("pause");
				break;
			}
			aim--;
			add_list(aim,Head, add);//����ڵ�
			system("pause");
			break;
		case 'c':
			system("cls");
			printf("\t\t----------         �������          ---------\n");
			judenum=judelist(Head);
			if (judenum == 0)break;
			out_list(Head);
			system("pause");
			break;
		case 'd':
			system("cls");
			printf("----------          ��������           ----------\n");
			judenum = judelist(Head);
			if (judenum == 0)break;
			oppolist(Head->next,Head);
			system("pause");
			break;
		case 'e':
			system("cls");
			printf("\t\t----------          �ҵ��������е�          ---------\n");
			judenum = judelist(Head);
			if (judenum == 0)break;
			mid(Head->next);
			system("pause");
			break;
		case 'f':
			system("cls");
			printf("\t\t----------           �ж��Ƿ�ɻ�          ---------\n");
			judenum=judelist(Head);
			if (judenum == 0)break;
			iscycle(Head);
			system("pause");
			break;

		case 'g':
			system("cls");
			printf("\t\t----------           ɾ���ڵ�ȡֵ          ---------\n");
			out_list(Head);
			judenum = judelist(Head);
			if (judenum == 0)break;
			del_list(Head);
			printf("ɾ���ɹ�");
			system("pause");
			break;
		case 'h':
			system("cls");
			printf("\t\t----------         ɾ������           ---------\n");
			judenum = judelist(Head);
			if (judenum == 0)break;
			del_alllist(Head);
			printf("ɾ���ɹ�����\n");
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
	printf("�������½ڵ�����ݣ�����Ϊ���֣�\n");
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
int count_list(List head) {//���������ݼ���
	int count = 0;
	while (head->next) {
		count++;
		head = head->next;
	}
	return count;
}
void oppolist(List headnext,List head) {//��ת����:�ѵ�ǰ��ָ����һ����Ȼ���������Ų
	List  fornt= NULL;
		List mid = headnext;
		while (mid) {
			List behide =mid->next;//��һ���ڵ㲻���䶪ʧ
			mid->next = fornt;
			fornt = mid;
			mid = behide;
		}
		head->next = fornt;
		printf("��ת��\n");
		out_list(head);
}
void mid(List head) {
	if (head == NULL) {
		printf("���ȴ�������\n");
		return;
	}
	List slow = head;
	List fast = head;
	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}
	printf("�м�ڵ��ֵΪ%d\n", slow->num);
}
int judelist(List Head) {//ͨ��a��ֵ�ж�����������
	int a = 1;
	if (Head == NULL || Head->next == NULL) {
		printf("���ȴ���������������\n");
		system("pause");
		a = 0;
		return a;
	}
}
void iscycle(List head) {//�ж��Ƿ�ɻ�
	List slow = head;
	List fast = head->next;
	while (slow != fast) {
		if (fast == NULL || fast->next == NULL) {
			printf("������û�гɻ�\n");
			return;
		}
		slow = slow->next;
		fast = fast->next->next;
	}
	printf("������ɻ�\n");
	return;
}
void del_list(List head) {//ɾ��ָ���ڵ�
	int delnum;
	printf("����������Ҫɾ���ڵĵ�ֵ\n");
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
void del_alllist(List Head) {//ɾ��ȫ������
	while(Head)
	{
		List nexthead = Head->next;
		free(Head);
		Head = nexthead;
	}
}
#endif
