#!/bin/bash
docker run --rm -it -v "$(pwd)":/wedstival-gba -w /wedstival-gba devkitpro/devkitarm:latest make $@
