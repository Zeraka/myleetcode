#include <stdio.h>
#include <stddef.h>
#include <string.h>


int char_array_replace(const char replaced_ch, const char* needed_str, char array[]);
/* Raw To Offer T.5*/
/*replace the string or char*/
char* char_replace(const char replaced_ch, const char* newstr, const char* target_str)
{
	return NULL;
}

/*
if you have a enough long char[] , you want to replace a char to a new str, you can use this function.
*/
int char_array_replace(const char replaced_ch, const char* needed_str, char array[])
{
	//traverse the array, count the replaced_ch.
	int numberOfReplacedCh = 0;
	int migrationLength = 0;

	char *p1 = NULL; 
	char *p2 = NULL;
	char *p3 = NULL;

	int n = 0;


	if(needed_str == NULL){
		return -2;
	}

	if(array == NULL){
		return -3;
	}

	for(int i = 0; i < strlen(array); i++)
	{
		if(array[i] == replaced_ch)
		{
			numberOfReplacedCh++;
		}
	}
	if(numberOfReplacedCh == 0)
	{
		return -4;
	}
	migrationLength = numberOfReplacedCh * strlen(needed_str) - numberOfReplacedCh;

	//printf("migrationLength=%d\n", migrationLength);
	//printf("sizeof(array)=%d\n", sizeof(array));
	//printf("length=%d\n", strlen(array));

	p1 = &array[strlen(array)];

	if(*p1 != '\0') return -5;

	p2 = p1 + migrationLength;

	while(p1 != p2){

		while(*p1 != replaced_ch){
			*p2 = *p1;
			*p1 = ' ';
			p1 = p1 -1;
			p2 = p2 -1 ;
			printf("p1=%s\n", p1);
		};

		p1--;
		
		n = strlen(needed_str);
		p3 = needed_str + n - 1;

		while(n != 0){
			*p2 = *p3;
			p2--;
			p3--;
			n--;	
		};
	}
	
	printf("array=%s\n",array);

	return 1;
}

int main(){
	char array[] = {'w','e',' ','a', 'r','e', ' ','h','a','p','p','y','.','\0','\0','\0','\0','\0','\0','\0','\0','\0'}; // 数组长度必须要足够长
	char * str = "%20";
	printf("%d\n",char_array_replace(' ', str, array));
	return 0;

}