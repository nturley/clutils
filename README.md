![build status](https://travis-ci.org/nturley/clutils.svg?branch=master)

I fought with autotools a lot when I first tried to get this to build. I found a couple of ways to get it up and running and I settled on the incantation in setup-autotools.sh. Then ./configure and then make.

If you branch, you'll probably need to change the travis config file, I got a little creative. I call make install and then harvest all the headers and binaries afterward and upload them along with the doxygen here: http://nturley-buildartifacts.s3-website-us-west-1.amazonaws.com/
