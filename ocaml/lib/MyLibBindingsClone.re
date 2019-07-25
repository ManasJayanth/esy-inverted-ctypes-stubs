open Ctypes;

let mylib_fn = () => 9999;

module Stubs = (I: Cstubs_inverted.INTERNAL) => {
  /* Structures declared here can be exposed to C too */
  /* let () = I.structure(handlers); */

  let () = I.internal("parse_xml", void @-> returning(int), mylib_fn);
};
