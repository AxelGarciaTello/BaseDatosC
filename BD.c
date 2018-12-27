#include <mysql.h>
#include <stdio.h>
#include <string.h>

void main(void){
	MYSQL *conn;
	MYSQL_RES *res;
	MYSQL_ROW row;
	char *server="localhost";
	char *user="root";
	char *password="12345";
	char *database="pruebac";
	conn=mysql_init(NULL);
	if(!mysql_real_connect(conn,server,user,password,database,0,NULL,0)){
		fprintf(stderr,"%s\n",mysql_error(conn));
		exit(1);
	}
	if(mysql_query(conn,"select * from datos;")){
		fprintf(stderr,"%s\n",mysql_error(conn));
		exit(1);
	}
	res=mysql_use_result(conn);
	while((row=mysql_fetch_row(res))!=NULL){
		printf("%s\n%s\n%s\n%s\n", row[0], row[1], row[2], row[3]);
	}
	mysql_free_result(res);
	mysql_close(conn);
	return;
}
