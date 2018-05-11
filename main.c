#include<stdio.h>
#include<stdlib.h>

struct tree{
	int value;
	struct tree *par;
	struct tree *left;
	struct tree *right;
	int black;//1 znaczy ze czarne 0 znaczy ze czerwone
};
  struct tree *root;//wskaznik na korzen

int LewaRotacja(struct tree* drzew){
        struct tree* y = (struct tree*)malloc(sizeof *root);
        y=drzew->right;
        drzew->right=y->left;
        if(y->left != NULL)
                y->left->par=drzew;
        y->par=drzew->par;
        if(drzew->par == NULL){
                root=y;
        }
        else if(drzew==drzew->par->left){
                drzew->par->left=y;
        }
        else drzew->par->right=y;
        y->left=drzew;
        drzew->par=y;
  return 0;
}

int PrawaRotacja(struct tree* drzew){
        struct tree* y = (struct tree*)malloc(sizeof *root);
        y=drzew->left;
        drzew->left=y->right;
        if(y->right != NULL)
                y->right->par=drzew;
        y->par=drzew->par;
        if(drzew->par == NULL){
                root=y;
        }
        else if(drzew==drzew->par->right){
                drzew->par->right=y;
        }
        else drzew->par->left=y;
        y->right=drzew;
        drzew->par=y;
  return 0;
}

int ustaw(struct tree* drzew){
        struct tree* uncle = (struct tree*)malloc(sizeof *root);
        while(drzew != root && drzew->par->black == 0){
            if(drzew->par == drzew->par->par->left){
                uncle = drzew->par->par->right;
                if(uncle != NULL && uncle->black == 0){
                    drzew->par->black = 1;
                    uncle->black = 1;
                    drzew->par->par->black = 0;
                    drzew = drzew->par->par;
                }
                else {
                    if (drzew == drzew->par->right) {
                        drzew = drzew->par;
                        LewaRotacja(drzew);
                    }
                    drzew->par->black = 1;
                    drzew->par->par->black = 0;
                    PrawaRotacja(drzew->par->par);
                }
            }
            else{
                uncle = drzew->par->par->left;
                if(uncle != NULL && uncle->black == 0){
                    drzew->par->black = 1;
                    uncle->black = 1;
                    drzew->par->par->black = 0;
                    drzew = drzew->par->par;
                }
                else {
                    if (drzew == drzew->par->left) {
                        drzew = drzew->par;
                        PrawaRotacja(drzew);
                    }
                    drzew->par->black = 1;
                    drzew->par->par->black = 0;
                    LewaRotacja(drzew->par->par);
                }
            }
        }
        root->black = 1;
  return 0;
}


int dodaj(int elem, struct tree *drzw){
//  jezeli drzewo jest puste to dodaj korzen
  if (root == NULL){
        root = (struct tree*)malloc(sizeof *root);
        root->value = elem;
        root->left = NULL;
        root->right = NULL;
        root->par = NULL;
	root->black=1;
  }
//jezeli zadana wartosc jest mniejsza od korzenia idz do lewego poddrzewa
  else if(elem < drzw->value){
          if(drzw->left != NULL){
                dodaj(elem,drzw->left);
          }
          else{
                struct tree *nowy = (struct tree*)malloc(sizeof *root);
                nowy->value = elem;
                nowy->left = NULL;
                nowy->right = NULL;
                nowy->par = drzw;
                drzw->left=nowy;
		nowy->black=0;
		ustaw(nowy);
          }
  }
//jezeli zadana wartosc jest wieksza lub rowna korzeniowi idz do prawego poddrzewa   
  else{
        if(drzw->right != NULL){
                dodaj(elem,drzw->right);
        }
        else{
                struct tree *nowy = (struct tree*)malloc(sizeof *root);
                nowy->value = elem;
                nowy->left = NULL;
                nowy->right = NULL;
                nowy->par = drzw;
                drzw->right=nowy;
		nowy->black=0;
		ustaw(nowy);
        }
  }
  return 0;
}

void szukaj(int serch,struct tree *drzew){
	if(drzew == NULL)
		printf("nie ma liczby %d na drzewie\n",serch);
	else if(serch == drzew->value){
		printf("liczba %d znajduje sie na drzewie ",serch);
		if(drzew->black==1)
			printf("i ma kolor czarny\n");
		else
			printf("i ma kolor czerwony\n");
	}
	else if(serch < drzew->value)
		szukaj(serch,drzew->left);
	else szukaj(serch,drzew->right);
}

void drukuj(struct tree *drzew){
	if(drzew != NULL){
		printf("(");
		drukuj(drzew->left);
		if(drzew == root)
			printf("@#$");
		if(drzew->black==1)//czarne sa zwykle a czerwone z =**=
			printf("%d,",drzew->value);
		else
			printf("=*%d*=,",drzew->value);
		drukuj(drzew->right);
		printf(")");
	}
}

int main(){

	printf("dodaje\n\n");
	dodaj(5,root);
	ustaw(root);
	drukuj(root);
	        putchar('\n');
	dodaj(10,root);
	ustaw(root);
	drukuj(root);
	        putchar('\n');
	dodaj(15,root);
	ustaw(root);
	drukuj(root);
	        putchar('\n');
	dodaj(7,root);
	ustaw(root);
	drukuj(root);
	        putchar('\n');
	dodaj(20,root);
	ustaw(root);
	drukuj(root);
	        putchar('\n');
	dodaj(25,root);
	ustaw(root);
	drukuj(root);
	        putchar('\n');
	dodaj(13,root);
	ustaw(root);
	drukuj(root);
	        putchar('\n');
	dodaj(11,root);
	ustaw(root);
	drukuj(root);
	        putchar('\n');
	dodaj(12,root);
	ustaw(root);
	drukuj(root);
	        putchar('\n');
/*	dodaj(22,root);
	ustaw(root);
	drukuj(root);
	        putchar('\n');
	dodaj(2,root);
	ustaw(root);
	drukuj(root);
	        putchar('\n');
	dodaj(7,root);
	ustaw(root);
	drukuj(root);
	        putchar('\n');
	szukaj(5,root);
	drukuj(root);
		putchar('\n');
*/
	return 0;
}
