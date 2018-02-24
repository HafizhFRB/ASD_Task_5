#include "player.h"
#include <ctime>

int randomInt(int  max_int) {
    srand(time(NULL));
    return (rand() % max_int) + 1;
}

void printInfo(List L) {
    /**
    * PR : menampilkan informasi ID, nama, dan lokasi file
    */

    address Q = first(L);
    do {
        cout<<"name    : "<<info(Q).name<<endl
            <<"ID      : "<<info(Q).ID<<endl
            <<"location: "<<info(Q).location<<endl;
        Q = next(Q);
    } while(Q!=first(L));
    cout<<"==============================================="<<endl;
}


void playMusic(address P) {
    /**
    * PR : memainkan lagu yang ditunjuk oleh pointer P
    */

    string filename = info(P).location+"/"+info(P).name;
    cout<<"playing "<<filename<<endl;
    PlaySound(TEXT(filename.c_str()), NULL, SND_FILENAME);
    _sleep(500); //delay 0.5 second
}


void shuffleList(List &L) {
    /**
    * PR : mengacak isi (elemen) dari list L
    * FS : isi (elemen) dari list teracak
    */
    //-------------your code here-------------
        address P;
        address Q;
        int x;
        P=first(L);
        x=randomInt(15);
        for(int i=1;i<=x;i++)
        {
                P=next(P);
        }
        deleteAfter(L,P,Q);
        insertFirst(L,Q);


    //----------------------------------------
}

void sortListByID(List &L) {
    /**
    * PR : mengurutkan isi (elemen) dari list L berdasarkan ID
    * FS : isi (elemen) dari list L terurut
    */
    //-------------your code here-------------
    List L2;
    address P;
    address Q;
    while (first(L)!=NULL)
    {
        P=first(L);
        deleteFirst(L,P);
        if (first(L2)==NULL)
        {
            insertFirst(L2,P);
        }
        else if (info(P).ID<info(first(L2)).ID)
        {
            insertFirst(L2,P);
        }
        else if (info(P).ID>info(last(L2)).ID)
        {
            insertLast(L2,P);
        }
        else
            Q=first(L2);
            while (info(Q).ID<info(P).ID)
            {
                Q=next(Q);
            }
            insertAfter(L2,Q,P);
    }
    L=L2;

    //----------------------------------------

}

void playRepeat(List &L, int n) {
    /**
    * PR : memainkan seluruh lagu di dalam list
    *      dari lagu pertama hingga terakhir sebanyak n kali
    */
    //-------------your code here-------------

        for (int i=1;i<=n;i++)
        {
            address P;
            P=first(L);
            do
            {
                playMusic(P);
            }
            while(P!=first(L));
        }


    //----------------------------------------
}

void deleteMusicByID(List &L, infotype x) {
    /**
    * IS : list L mungkin kosong
    * PR : menerima input user untuk ID lagu yang ingin dihapus
    *      jika ID lagu ditemukan, hapus (deallocate) lagu dari list
    * FS : elemen dengan ID yang dicari dideallocate
    */
    //-------------your code here-------------
    if (first(L)!=NULL)
    {
        address P;
        address Q;
        P=findElmByID(L,x);
        if(P!=NULL)
        {
            Q=prev(P);
            deleteAfter(L,Q,P);
            deallocate(P);
        }
    }
    //----------------------------------------

}
