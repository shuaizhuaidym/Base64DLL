Action()
{
	char *user_name = "Michael Sylvester Gardenzio Stallone(西尔维斯特·史泰龙)";
	char *pwd = "ppnn13%dkstFeb.1st";

	int src_len = strlen(pwd);
	int dst_len = Base64encode_len(src_len);

	char * encode_pwd = (char*)malloc(sizeof(char) * dst_len);

	//调用1
	Init(user_name, pwd);

	lr_output_message("Src length: [%d], Target length: [%d]\r\n", src_len, dst_len);

	//调用2
    Base64encode(encode_pwd, pwd, src_len);

	lr_log_message("Base64 encode pwd:[%s]\r\n", encode_pwd);

	free(encode_pwd);//attention

	return 0;
}