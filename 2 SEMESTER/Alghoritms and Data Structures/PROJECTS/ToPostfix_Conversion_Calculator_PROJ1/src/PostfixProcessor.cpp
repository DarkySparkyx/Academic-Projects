#include "PostfixProcessor.h"
#include <cstring>


PostfixProcessor::PostfixProcessor()
{
    size=0;
    memory=20;
    postfix = new char[20];
}

int FastPrioCheck(char input)
{
    switch(input)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case 'M':
        return 4;
    case ',':
    case '(':
    case ')':
        return -1;
    case 'I':
        return 3;
    case 'N':
        return 3;
    default:
        return 3;
    }
    return -1;
}
void PostfixProcessor::OperatorDetected(char input)
{
    int inputprio=FastPrioCheck(input);
    int comacounter=0;
    char cache[4]="";
    switch(input)
    {
    case ',':
        while(inputprio=stos.GetTop()->GetCode(),inputprio!=4 && inputprio!=8)
        {
            stos.pop(postfix,&size);
            postfix[size++]=' ';
        }
        stos.push(input);
        break;
    case '(':
        stos.push(input);
        break;
    case ')':
        while(inputprio=stos.GetTop()->GetCode(), !stos.IsEmpty() && inputprio!=4)
        {
            if(inputprio==8)
            {
                comacounter++;
                stos.TopDelete();
            }
            else
            {
                stos.pop(postfix,&size);
                postfix[size++]=' ';
            }

        }
        stos.TopDelete();
        if(!stos.IsEmpty() && stos.GetTop()->GetName()[0]=='M')
        {
            stos.GetTop()->AddNumber(comacounter);
        }

        break;
    case '+':
    case '-':
    case '*':
    case '/':
        while(!stos.IsEmpty() && stos.GetTop()->GetPrio()>=inputprio)
        {
            stos.pop(postfix,&size);
            postfix[size++]=' ';
        }
        stos.push(input);
        break;
    case 'N':
        while(!stos.IsEmpty() && stos.GetTop()->GetPrio()>inputprio)
        {
            stos.pop(postfix, &size);
        }
        stos.push(input);
        break;
    case 'I':
        getchar();
        cache[0]='I';
        cache[1]='F';
        cache[2]='\0';
        stos.push(cache);
        break;
    case 'M':
        cache[0]=input;
        cache[1]=getchar();
        cache[2]=getchar();
        while(!stos.IsEmpty() && stos.GetTop()->GetPrio()>=inputprio)
        {
            stos.pop(postfix,&size);
            postfix[size++]=' ';
        }
        stos.push(cache);
    }
}

void PostfixProcessor::Converter()
{
    char input;
    while(input=getchar(),input!='.')
    {
        if(input>47 && input<59)
        {
            postfix[size]=input;
            size++;
        }
        else if(input==' ')
        {
            if(postfix[size-1]!=32 && size!=0)
            {
                postfix[size]=' ';
                size++;
            }
        }
        else
        {
            OperatorDetected(input);
        }
        if(double(size)/double(memory)>0.8)
        {
            postfix = (char *) realloc(postfix, memory*1.6);
            memory=memory*1.6;
        }
    }

    while(!stos.IsEmpty())
    {
        stos.pop(postfix,&size);
        postfix[size]=' ';
        size++;
    }
    postfix[size]='\0';
    //printf("%s\n",postfix);
    postfix[size++]='.';
    postfix[size]='\0';
}

int PostfixProcessor::Dodawanie()
{
    int a = StosInt.pop();
    int b = StosInt.pop();

    return b + a;
}

int PostfixProcessor::Odejmowanie()
{
    int a = StosInt.pop();
    int b = StosInt.pop();

    return b - a;
}

int PostfixProcessor::Mnozenie()
{
    int a = StosInt.pop();
    int b = StosInt.pop();

    return b * a;
}

bool PostfixProcessor::Dzielenie()
{
    int a = StosInt.pop();
    int b = StosInt.pop();
    if(a!=0)
    {
        StosInt.push(b/a);
        return false;
    }
    else
    {
        return true;
    }
}

int PostfixProcessor::Maximum(int ile)
{
    int result=StosInt.pop();
    int cache=0;
    for(int i=0; i<ile-1; i++)
    {
        cache=StosInt.pop();
        if(cache>result)
            result=cache;
    }
    return result;

}

int PostfixProcessor::Minimum(int ile)
{
    int result=StosInt.pop();
    int cache=0;
    for(int i=0; i<ile-1; i++)
    {
        cache=StosInt.pop();
        if(cache<result)
            result=cache;
    }
    return result;

}

int PostfixProcessor::Warunek()
{
    int c = StosInt.pop();
    int b = StosInt.pop();
    int a = StosInt.pop();
    if(a>0)
        return b;
    else
        return c;
}
void PostfixProcessor::Calculator()
{
    char znak[20];
    int i=0;
    int j=0;
    bool error=false;
    while(znak[i]=postfix[j],znak[i]!='.')
    {
        if(znak[i]==' ')
        {
            znak[i]='\0';
            if(znak[0]>47 && znak[0]<58)
            {
                StosInt.push(atoi(znak));
            }
            else
            {
                switch(znak[0])
                {
                case '+':
                    //printf("%s ",znak);
                    //StosInt.ShowContent();
                    StosInt.push(Dodawanie());
                    break;
                case '-':
                    printf("%s ",znak);
                    //StosInt.ShowContent();
                    StosInt.push(Odejmowanie());
                    break;
                case '*':
                    printf("%s ",znak);
                    //StosInt.ShowContent();
                    StosInt.push(Mnozenie());
                    break;
                case '/':
                    printf("%s ",znak);
                    //StosInt.ShowContent();
                    if(Dzielenie())
                    {
                        error=true;
                    }
                    break;
                case 'M':
                    printf("%s ",znak);
                    //StosInt.ShowContent();
                    if(znak[1]=='A')
                    {
                        char* test=znak+3;
                        StosInt.push(Maximum(atoi(test)));
                    }
                    else
                    {
                        char* test=znak+3;
                        StosInt.push(Minimum(atoi(test)));
                    }
                    break;
                case 'I':
                    printf("%s ",znak);
                    //StosInt.ShowContent();
                    StosInt.push(Warunek());
                    break;
                case 'N':
                    printf("%s ",znak);
                    //StosInt.ShowContent();
                    StosInt.push(-StosInt.pop());
                    break;
                }
            }
            i=-1;
        }
        if(error)
        {
            printf("ERROR\n");
            break;
        }
        i++;
        j++;
    }

    if(!error)
    {
        printf("%d\n",StosInt.pop());
    }
}



PostfixProcessor::~PostfixProcessor()
{
    delete[] postfix;
}
