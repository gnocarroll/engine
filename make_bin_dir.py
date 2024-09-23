"""
The purpose of this program is to create a binary directory file structure that
imitates the file structure of the directory containing the project's code. The
directories created in this process will have an empty .gitignore added to them
so that they can be committed to a git repository.

I am deciding to organize the binary directories in the project I am creating
this for like this so this is a useful script.
"""


import argparse
import os
import sys


ARG_NAME = "dir_prefix"


parser = argparse.ArgumentParser(
    prog=os.path.split(__file__)[1],
    description="create file structure for bin directory",
)

parser.add_argument(
    ARG_NAME,
    help="prefix for bin directory name",
)

parser.add_argument(
    "-d",
    "--dir",
    default="engine",
    help="directory whose file structure you want to imitate",
    required=False,
)

args = vars(parser.parse_args())

bin_dir = args[ARG_NAME] + "_bin"


def create_dirs(target_dir: str = "") -> None:
    # New dir that may need to be created and have .gitignore added
    new_dir_path = os.path.join(bin_dir, target_dir)

    if not os.path.exists(new_dir_path):
        os.mkdir(new_dir_path)
        open(os.path.join(new_dir_path, ".gitignore"), "a").close()

    # Where to search for new directories that may need to be reflected in bin
    # directory
    target_dir_path = os.path.join(args["dir"], target_dir)

    for filename in os.listdir(target_dir_path):
        filepath = os.path.join(target_dir_path, filename)

        if os.path.isdir(filepath):
            create_dirs(os.path.join(target_dir, filename))


create_dirs()
