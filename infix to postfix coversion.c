#include<stdio.h>
#include<string.h>
#include<math.h>
char outstack[50],instack[50],str[50];
int otop = -1,itop = -1,etop=-1,i,j,count=0;
void POSTFIX(){
		    otop += 1;                     
	    	outstack[otop] = instack[itop];
	        itop -= 1; 
}
void operator_stack(){
	    	itop += 1;
	     instack[itop] = str[i];	        
}
int main(){
	printf("\n");
	scanf("%[^\n ]s",str);
	if((str[i]>='0' && str[i]<='9')){
		otop += 1;
		outstack[otop] = str[0];
	}
	else{
		itop += 1;
		instack[itop] = str[0];
	}
    for(i=1;i<strlen(str);i++)
	{
    	if((str[i]>='0' && str[i]<='9') || (str[i]>='A' && str[i]<='Z')){
		otop += 1;
		outstack[otop] = str[i];
	}
	    else if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
        operator_stack();	
		}
	    else if(str[i]=='+' || str[i]=='-'){
	    	while(1){
	    		if((instack[itop]=='*' || instack[itop]=='/' || instack[itop]=='^' || instack[itop]=='+' || instack[itop]=='-'|| instack[itop]=='%') && itop!=-1){
                       POSTFIX();
				}
				else{
                  operator_stack();
	                break;
				}
		
			}
		}
		else if(str[i]=='*' || str[i]=='/' || str[i] == '%'){
			 while(1){
			 	if((instack[itop]=='*' || instack[itop]=='/' || instack[itop]=='^' || instack[itop]=='%') && itop!=-1){
                        POSTFIX();
				 }
				 else{
                    operator_stack();
	                break;
				}
			 }
		}
		else if(str[i]=='^'){
        operator_stack();		
		}
		else if(str[i]==')'){
			while(1){
				if(instack[itop]=='('){
					itop -= 1;
					break;
				}
				else{
                       POSTFIX();				
				}
			}
		}
			else if(str[i]=='}'){
			while(1){
				if(instack[itop]=='{'){
					itop -= 1;
					break;
				}
				else{
                       POSTFIX();				
				}
			}
		}
		else if(str[i]==']'){
			while(1){
				if(instack[itop]=='['){
					itop -= 1;
					break;
				}
				else{
                       POSTFIX();				
				}
			}
		}
	}
for(i=itop;i>-1;i--){
	    			otop += 1;
	    			outstack[otop] = instack[i];	
}
for(i=0;i<strlen(outstack);i++)
         printf("%c ",outstack[i]);
}
