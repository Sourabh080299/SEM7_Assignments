#define N 4
byte printer[N];
byte nr_print;
proctype office(byte id)
{
    Think:
        printf("\noffice with id no. %d is WAITING\n",id);
        if
        :: atomic { printer[id] == 0 -> printer[id] = id + 1; };
        :: atomic { printer[(id + 1)%N] == 0 -> printer[(id + 1)%N] = id + 1; };
        fi;
    One:
        if
        :: atomic
        {
            printer[id] == id + 1 -> printer[(id + 1)%N] == 0 -> printer[(id + 1)%N] = id + 1;
            nr_print++;
        } 
        :: atomic
        {
            printer[id] == 0 -> printer[(id + 1)%N] == id + 1 -> printer[id] = id + 1;
            nr_print++;
        } 
        fi;
    Eat:
        printf("\noffice with id no. %d is PRINTING\n",id);
        d_step { nr_print--; printer[(id + 1)%N] = 0; printer[id] = 0;}
    goto Think;
}

init {
    atomic
    {
        byte i = 0;
        do
        :: i < N -> run office(i); i++;
        :: else -> break;
        od;
    }
}