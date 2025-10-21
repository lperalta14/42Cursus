
#include "../philo.h"

void    printdead(t_data *table, int id)
{
    long    current;
    pthread_mutex_lock(&table->print_mutex);
    current = get_time() - table->start_time;
    printf("%s%ld %d died%s\n",RED, current, table->philos[id].dni, NC);
    pthread_mutex_unlock(&table->print_mutex);
}

//visar que todos comen()

int check_death(t_data  *table)
{
    int  i;
    t_philo *philo;
    long    hungry;

    i = 0;
    philo = table->philos;
    while (i < table->num_philos)
    {
        
        pthread_mutex_lock(&table->meal_mutex);
        hungry = get_time() - philo[i].last_meal_time;
        pthread_mutex_unlock(&table->meal_mutex);
        if (hungry > table->time_to_die)
        {
            printdead(table, i);
            pthread_mutex_lock(&table->stop_mutex);
            table->not_dead_yet = 0;
            pthread_mutex_unlock(&table->stop_mutex);
            return (1);
        }
        i++;
    }
    return (0);
}

void    *staff(void *arg)
{
    t_data  *table;

    table = (t_data *)arg;
    while(42)
    {
        if (check_death(table))
            return (NULL);
        if (table->must_eat_count != -1)
        {
            /*
            if (check_all_ate(table))
            {
                pthread_mutex_lock(&table->stop_mutex);
                table->not_dead_yet = 0;
                pthread_mutex_unlock(&table->stop_mutex);
                return (NULL);
            }
            */
        }
        usleep(1000);
    }
}