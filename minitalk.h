/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeper <ezeper@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:41:44 by ezeper            #+#    #+#             */
/*   Updated: 2024/07/29 18:01:03 by ezeper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

void	handle_sigusr(int signum, siginfo_t *info, void *context)
void	send_str(pid_t pid, char *str);
void	handle_signal(int signum);

typedef struct data {
    char tmp;     // Temporary char
    int i;        // Bit inde
    int len;      // Length of the message
    int is_len;   // Flag to indicate if length is set 
    int pid;      // Process ID 
} t_data;

// Data structure for storing new string data and related information
typedef struct new_data {
    char str[100];  // String buffer 
    int chr_count;  // Character count // K
    int str_count;  // String count // 
    int len;        // Length of the string // D
    char tmp;       // Temporary character
    int is_len;     // Flag to indicate if length is set 
} t_new_data;

#endif