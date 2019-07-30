open Ctypes;

let mylib_fn = () => 99997777;

module Stubs = (I: Cstubs_inverted.INTERNAL) => {
  /* Structures declared here can be exposed to C too */
  /* let () = I.structure(handlers); */

  let () =
    I.internal("mylib_fn_exported", void @-> returning(int), mylib_fn);
};
