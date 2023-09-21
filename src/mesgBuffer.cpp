struct mesg_buffer {
    long mesg_type;
    char mesg_text[100];
};

struct mesg_buffer_fetch {
    long mesg_type;
    char** mesg_text;
};