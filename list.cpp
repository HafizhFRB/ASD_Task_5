#include "list.h"

void createList(List &L) {
    /**
    * FS : first(L) dan last(L) diset Nil
    */
    //-------------your code here-------------
    first(L)=NULL;
    last(L)=NULL;
    //----------------------------------------
}

address allocate(infotype x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x,
    *      next dan prev elemen = Nil
    */

    address P = NULL;
    //-------------your code here-------------
    info(P)=x;
    next(P)=NULL;
    prev(P)=NULL;
    //----------------------------------------
    return P;
}

void deallocate(address &P) {
    /**
    * FS : menghapus elemen yang ditunjuk oleh P (delete)
    */
    //-------------your code here-------------
    delete P;
    //----------------------------------------
}

void insertFirst(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List L
    */
    //-------------your code here-------------
    if (first(L)==NULL)
    {
        first(L)=P;
        last(L)=P;
        next(P)=P;
        prev(P)=P;
    }
    else
    {
        next(P)=first(L);
        prev(P)=last(L);
        next(last(L))=P;
        prev(first(L))=P;
        first(L)=P;
    }
    //----------------------------------------
}

void insertLast(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List L
    */
    //-------------your code here-------------
        if (first(L)==NULL)
    {
        first(L)=P;
        last(L)=P;
        next(P)=P;
        prev(P)=P;
    }
    else
    {
        next(P)=first(L);
        prev(P)=last(L);
        next(last(L))=P;
        prev(first(L))=P;
        last(L)=P;
    }
    //----------------------------------------
}

address findElmByID(List L, infotype x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.ID = x.ID,
           mengembalikan Nil jika tidak ditemukan
    */

    address P = NULL;
    //-------------your code here-------------
    if (first(L)==NULL)
    {
        cout<<"List Kosong";
    }
    else
    {
        P=first(L);
        do {
         if (info(P).ID==x.ID)
         {
             return P;
         }
        }while(P!=first(L));

    }
    //----------------------------------------
    return NULL;
}

address findElmByName(List L, infotype x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.name = x.name,
           mengembalikan Nil jika tidak ditemukan
    */

    address P = NULL;
    //-------------your code here-------------
    if (first(L)==NULL)
    {
        cout<<"List Kosong";
    }
    else
    {
        P=first(L);
        do {
         if (info(P).name==x.name)
         {
             return P;
         }
        }while(P!=first(L));

    }
    //----------------------------------------
    return NULL;
}

void deleteFirst(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen pertama di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    if (first(L)==NULL)
    {

    }
    else
    {
        P=first(L);
        next(last(L))=next(P);
        prev(next(P))=last(L);
        first(L)=next(P);
        next(P)=NULL;
        prev(P)=NULL;
    }
    //----------------------------------------
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen tarakhir di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
        if (first(L)==NULL)
    {

    }
    else
    {
        P=last(L);
        next(prev(P))=first(L);
        prev(first(L))=prev(P);
        last(L)=prev(P);
        next(P)=NULL;
        prev(P)=NULL;
    }
    //----------------------------------------
}

void insertAfter(List &L, address &Prec, address P) {
    /**
    * IS : Prec dan P tidak NULL
    * FS : elemen yang ditunjuk P menjadi elemen di belakang elemen yang
    *      ditunjuk pointer Prec
    */
    //-------------your code here-------------
    if(Prec!=NULL)
    {
        if(Prec==last(L))
        {
            insertFirst(L,P);
        }
        else if(Prec==prev(last(L)))
        {
            insertLast(L,P);
        }
        else
        {
            next(P)=next(Prec);
            prev(P)=Prec;
            prev(next(Prec))=P;
            next(Prec)=P;
        }
    }
    //----------------------------------------

}
void deleteAfter(List &L, address &Prec, address &P) {
    /**
    * IS : Prec tidak NULL
    * FS : elemen yang berada di belakang elemen Prec dilepas
    *      dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
        if(Prec!=NULL)
    {
        if(Prec==last(L))
        {
            deleteFirst(L,P);
        }
        else if(Prec==prev(last(L)))
        {
            deleteLast(L,P);
        }
        else
        {
            P=next(Prec);
            next(Prec)=next(P);
            prev(next(P))=Prec;
            next(P)=NULL;
            prev(P)=NULL;
        }
    }
    //----------------------------------------
}

