/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:14:05 by jabecass          #+#    #+#             */
/*   Updated: 2023/02/16 17:09:44 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: program <input file> <command 1> <command 2> <output file>\n");
        return 1;
    }
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }
    FILE *output_file = fopen(argv[4], "w");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        return 1;
    }
    // Build the command string
    char command[1024];
    snprintf(command, sizeof(command), "%s %s | %s > %s",
             argv[2], argv[1], argv[3], argv[4]);
    // Execute the command
    FILE *pipe = popen(command, "r");
    if (pipe == NULL) {
        printf("Error: could not execute command.\n");
        return 1;
    }
    // Read the output of the command and save it to the output file
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        fputs(buffer, output_file);
    }
    pclose(pipe);
    fclose(input_file);
    fclose(output_file);
    return 0;
}
