int test_permutation(char *str){

	if(str == nullptr)
	{
		return 0;
	}

	Permutation(str, str);
}

int Permutation(char *str, char * begin){

	//如果begin为'\0',则打印出字符
	if(begin == '\0')
	{
		printf("%s\n". str);
		return 0;
	}
	else
	{	
		//遍历该数组
		for(char *p = begin; p !='\0'; p++){

			char temp = *p ;
			
			Permutation(str, begin + 1);

		}
	}
}