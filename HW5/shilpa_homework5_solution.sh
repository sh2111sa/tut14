#!/bin/bash
# SLURM job description parameters
#SBATCH -J computer-info-job   # Job name
#SBATCH -o computer-info.out  # Output file
#SBATCH -e computer-info.err  # Error file
#SBATCH -t 00:10:00          # Max runtime (HH:MM:SS)

# Gather information about the computer
hostname
uptime
df -h
echo "Number of entries in /etc directory: $(ls /etc | wc -l)"
echo "Number of entries in /usr/bin directory: $(ls /usr/bin | wc -l)"

# Sleep for a few minutes (300 seconds)
sleep 300