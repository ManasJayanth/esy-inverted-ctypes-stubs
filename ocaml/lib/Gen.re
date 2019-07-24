/*
 * Copyright (c) 2014-2015 Jeremy Yallop.
 *
 * This file is distributed under the terms of the MIT License.
 * See the file LICENSE for details.
 */

/** A driver for stub generation.  Build OCaml and C code from the
    Bindings.Stubs functor. */;

let generate = () => {
  let dirname = Sys.getcwd();
  let prefix = "mylib";
  let path = basename => Filename.concat(dirname, basename);
  let ml_fd = open_out(path("mylib_generated_bindings.ml"));
  let c_fd = open_out(path("mylib.c"));
  let h_fd = open_out(path("mylib.h"));
  let stubs: module Cstubs_inverted.BINDINGS = (module Bindings.Stubs);
  {
    /* Generate the ML module that links in the generated C. */
    Cstubs_inverted.write_ml(
      Format.formatter_of_out_channel(ml_fd),
      ~prefix,
      stubs,
    );

    /* Generate the C source file that exports OCaml functions. */
    Format.fprintf(
      Format.formatter_of_out_channel(c_fd),
      "#include \"mylib.h\"@\n%a",
      Cstubs_inverted.write_c(~prefix),
      stubs,
    );

    /* Generate the C header file that exports OCaml functions. */
    Cstubs_inverted.write_c_header(
      Format.formatter_of_out_channel(h_fd),
      ~prefix,
      stubs,
    );
  };
  close_out(h_fd);
  close_out(c_fd);
  close_out(ml_fd);
};

let () = generate();
