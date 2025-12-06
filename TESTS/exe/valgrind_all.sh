#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    valgrind_all.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/09 11:58:22 by ncruz-ne          #+#    #+#              #
#    Updated: 2025/12/06 16:11:15 by ncruz-ne         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

#!/bin/sh

SCRIPT_DIR=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)

mkdir -p TESTS/outputs
mkdir -p TESTS/valgrind

for exe in "$SCRIPT_DIR"/*; do
    if [ -f "$exe" ] && [ -x "$exe" ]; then
        exe_name=$(basename "$exe")
        
        # Skip the script itself
        if [ "$exe_name" = "$(basename "$0")" ]; then
            continue
        fi

        echo "Running Valgrind on $exe_name..."
        valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all \
            --log-file="TESTS/valgrind/valgrind_leakcheck_${exe_name}.log" "$exe" \
            > TESTS/outputs/${exe_name}.txt 
    fi
done
