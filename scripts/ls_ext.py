import argparse
import os
import sys


parser = argparse.ArgumentParser(
    prog=os.path.split(__file__)[1],
    description=(
        "write all filepaths ending in provided extension(s) in dir and all "
        "subdirs to stdout"
    )
)

parser.add_argument(
    "ext",
    help="file extension for paths to list",
    nargs="+",
)

parser.add_argument(
    "-d",
    "--dir",
    default=".",
    help="dir to source files from",
    required=False,
)

args = parser.parse_args()

if not os.path.isdir(args.dir):
    sys.exit(f"Target dir {args.dir} not found or is not a dir")

for arg_ext in args.ext:
    if len(arg_ext) == 0 or arg_ext[0] != ".":
        sys.exit(
            f"Extension {arg_ext} has length 0 or does not begin with '.'",
        )


def _listdir_paths(target_dir: str):
    for filename in os.listdir(target_dir):
        yield os.path.join(target_dir, filename)


def _any_ext_match(filepath: str) -> bool:
    _, ext = os.path.splitext(filepath)

    return any([ext == arg_ext for arg_ext in args.ext])


def ls_w_ext(target_dir: str) -> None:
    for filepath in _listdir_paths(target_dir):
        if os.path.isdir(filepath):
            ls_w_ext(filepath)
        elif _any_ext_match(filepath):
            print(filepath)


ls_w_ext(args.dir)

