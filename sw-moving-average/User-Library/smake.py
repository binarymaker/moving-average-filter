#!/usr/bin/env python

import argparse, uuid
from os import path
from datetime import date

year = str(date.today().year)
copyright_tmpl = \
"""
/**
  ******************************************************************************
  * ______  _                             ___  ___        _               
  * | ___ \(_)                            |  \/  |       | |              
  * | |_/ / _  _ __    __ _  _ __  _   _  | .  . |  __ _ | | __ ___  _ __ 
  * | ___ \| || '_ \  / _` || '__|| | | | | |\/| | / _` || |/ // _ \| '__|
  * | |_/ /| || | | || (_| || |   | |_| | | |  | || (_| ||   <|  __/| |   
  * \____/ |_||_| |_| \__,_||_|    \__, | \_|  |_/ \__,_||_|\_\\\\___||_|   
  *                                 __/ |                                 
  *                                |___/                                  
  *                                                                       
  * Copyright (C) """ + year + """ Binary Maker - All Rights Reserved
  *
  * This program and the accompanying materials are made available
  * under the terms described in the LICENSE file which accompanies
  * this distribution.
  * Written by Binary Maker <https://github.com/binarymaker>
  ******************************************************************************
  */
"""

header_incl_tmpl = \
"""
#ifndef BM_%(uuid)s
#define BM_%(uuid)s


#endif // BM_%(uuid)s
"""

def h_create (file_handle):
    file_handle.write (copyright_tmpl)
    file_handle.write (header_incl_tmpl %
                       ({'uuid': str(uuid.uuid1()).replace('-','_'),}))
    file_handle.close ()

def src_create (file_handle):
    file_handle.write (copyright_tmpl)
    file_handle.close ()

def main():
    parser = argparse.ArgumentParser (
        prog="stool", description="C/C++ source and header file generation tool")
    parser.add_argument ("-f", "--file-name",
                         help="C/C++ header/source file name",
                         type=str, required=True)
    args = vars(parser.parse_args ())

    c_file = open(args['file_name'] +'.c','w')
    h_file = open(args['file_name'] +'.h','w')
    cfg_file = open(args['file_name'] +'-cfg.h','w')

    h_create(h_file)
    h_create(cfg_file)
    src_create(c_file)

if __name__ == "__main__":
    main ()