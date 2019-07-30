#include <stdio.h>
#include <caml/callback.h>

#include "mylib.h"

/* int main(int argc, char **argv) { */
/*     printf("mylib_fn_exported: %d\n", mylib_fn_exported()); */
/*     return 0; */
/* } */
#include <dlfcn.h>
#include <stdio.h>
#include <caml/mlvalues.h>
#include <caml/callback.h>

int hello_closure()
{
  void *camllib;
  int (*camllib_foo)(void);
  int imghandle;


  camllib = dlopen("caml_mylib.so", RTLD_LAZY);
  if ( camllib != NULL ) {
      printf("Library loaded successfully!\n");
      camllib_foo = dlsym(camllib, "mylib_fn_exported");
      if (camllib_foo != NULL) {
          return camllib_foo();
      } else {
          printf("Sym not found\n");
          return -1;
      }
  } else {
       printf("It was NULL\n");
       return -1;
  }
  /* ... */
  if (camllib != NULL ) dlclose(camllib);
  /* return EXIT_SUCCESS; */
  /*   static value * closure_f = NULL; */
  /*   if (closure_f == NULL) { */
  /*       closure_f = caml_named_value("main"); */
  /*   } */
  /*   return Int_val(caml_callback(*closure_f, Val_unit)); */
}



int main(int argc, char **argv)
{
    caml_main(argv);
    printf("Return value: %d\n", hello_closure());
    return 0;
}
