#ifndef TESTPROGRAMFILE_UNITTESTS_H
#define TESTPROGRAMFILE_UNITTESTS_H

#ifdef DEBUG
#define UNITTEST(what, opera, truth) \
{\
    if(!((what) opera (truth)))\
        printf("FAIL in testing  %s != %s\n", #what, #truth);\
    else\
        printf("Test passed\n");\
};
#else
#define UNITTEST(what, opera, truth)
#endif

#endif //TESTPROGRAMFILE_UNITTESTS_H