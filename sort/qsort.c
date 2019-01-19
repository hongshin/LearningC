/* https://www.gnu.org/software/libc/manual/html_mono/libc.html#Search_002fSort-Example */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct critter
{
		const char *name;
		const char *species;
};

struct critter muppets[] =
{
		{"Kermit", "frog"},
		{"Piggy", "pig"},
		{"Gonzo", "whatever"},
		{"Fozzie", "bear"},
		{"Sam", "eagle"},
		{"Robin", "frog"},
		{"Animal", "animal"},
		{"Camilla", "chicken"},
		{"Sweetums", "monster"},
		{"Dr. Strangepork", "pig"},
		{"Link Hogthrob", "pig"},
		{"Zoot", "human"},
		{"Dr. Bunsen Honeydew", "human"},
		{"Beaker", "human"},
		{"Swedish Chef", "human"}
};

int count = sizeof (muppets) / sizeof (struct critter);
int critter_cmp 
  (const void *v1, const void *v2)
  {
		const struct critter *c1 = v1;
		const struct critter *c2 = v2;

		return strcmp(c1->species, c2->species) *-1 ;
  }

void
print_critter (const struct critter *c)
{
		printf ("%s, the %s\n", c->name, c->species);
}

int
main (void)
{
		int i;

		qsort(muppets, 15, sizeof(struct critter), critter_cmp);

		for (i = 0; i < count; i++)
				print_critter (&muppets[i]);
		printf ("\n");

		return 0;
}
