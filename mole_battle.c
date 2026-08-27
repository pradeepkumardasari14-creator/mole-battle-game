#include <stdio.h>
#include <math.h>

// Function to check if a number is prime
int isPrime(int num) {
    if (num < 2) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;
    
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}

// Function to check if a number is Armstrong (narcissistic)
int isArmstrong(int num) {
    int original = num;
    int digitCount = 0;
    int temp = num;
    
    // Count number of digits
    while (temp > 0) {
        digitCount++;
        temp /= 10;
    }
    
    // Calculate sum of each digit raised to power of digit count
    int sum = 0;
    temp = num;
    while (temp > 0) {
        int digit = temp % 10;
        int power = 1;
        for (int i = 0; i < digitCount; i++) {
            power *= digit;
        }
        sum += power;
        temp /= 10;
    }
    
    return sum == original;
}

// Function to check if a number is perfect
int isPerfect(int num) {
    if (num <= 1) return 0;
    
    int sum = 0;
    
    // Find all divisors and sum them (excluding the number itself)
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    
    return sum == num;
}

// Function to determine mole category and return category type
// Returns: 1 = Royal, 2 = Guardian, 3 = Sacred, 4 = Common
int getMoleCategory(int num, const char** category) {
    if (isPerfect(num)) {
        *category = "Royal Mole";
        return 1;
    }
    else if (isArmstrong(num)) {
        *category = "Guardian Mole";
        return 2;
    }
    else if (isPrime(num)) {
        *category = "Sacred Mole";
        return 3;
    }
    else {
        *category = "Common Mole";
        return 4;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    int moles[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &moles[i]);
    }
    
    int sacredSum = 0, guardianSum = 0, royalSum = 0;
    
    // Process each mole
    for (int i = 0; i < n; i++) {
        const char* category;
        int type = getMoleCategory(moles[i], &category);
        
        printf("%d - %s\n", moles[i], category);
        
        // Add to respective sum based on category
        if (type == 1) {
            royalSum += moles[i];
        }
        else if (type == 2) {
            guardianSum += moles[i];
        }
        else if (type == 3) {
            sacredSum += moles[i];
        }
        // Common moles don't contribute to battle score
    }
    
    // Calculate Battle Score
    int battleScore = sacredSum + (guardianSum * 2) + (royalSum * 3);
    
    printf("Battle Score: %d\n", battleScore);
    
    return 0;
}
