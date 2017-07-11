#!/bin/bash
rsb logger --idl-path "rst/trunk/rst/proto/sandbox/"   \
             --idl-path "rst/trunk/rst/proto/stable/"    \
             --load-idl 'rst/trunk/rst/proto/**/*.proto' \
             --style detailed                            \
             spread:alice.techfak.uni-bielefeld.de
