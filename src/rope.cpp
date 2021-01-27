#include <iostream>
#include <vector>

#include "CGL/vector2D.h"

#include "mass.h"
#include "rope.h"
#include "spring.h"
namespace CGL {

    Rope::Rope(Vector2D start, Vector2D end, int num_nodes, float node_mass, float k, vector<int> pinned_nodes)
    {
        // TODO (Part 1): Create a rope starting at `start`, ending at `end`, and containing `num_nodes` nodes.

//        To Comment-in this part when you implement the constructor 
//        for (auto &i : pinned_nodes) {
//            masses[i]->pinned = true;
//        }
    
          for (int i = 0; i < num_nodes - 1; i++)
          {
              if (i == 0)
              {
                  Mass* m1 = new Mass(start, node_mass, true);
                  masses.push_back(m1);
                  if (i + 1 < num_nodes-1)
                  {     
                      Mass* m2= new Mass(start + (i + 1)*(end - start) / (num_nodes - 1), node_mass, true);
                      masses.push_back(m2);
                      springs.push_back(new Spring(m1, m2, k));
                  }
                  
              }
              else if (i == num_nodes - 2)
              {
                  Mass* m1= masses[i];
                  Mass* m2 = new Mass(end, node_mass, true);
                  springs.push_back(new Spring(m1, m2, k));
              }
              else
              {
                Mass* m1= masses[i];
                Mass* m2= new Mass(start + (i + 1)*(end - start) / (num_nodes - 1), node_mass, true);
                masses.push_back(m2);
                springs.push_back(new Spring(m1, m2, k));
              }
              

          }
          

    }

    void Rope::simulateEuler(float delta_t, Vector2D gravity)
    {
        for (auto &s : springs)
        {
            // TODO (Part 2): Use Hooke's law to calculate the force on a node
        }

        for (auto &m : masses)
        {
            if (!m->pinned)
            {
                // TODO (Part 2): Add the force due to gravity, then compute the new velocity and position

                // TODO (Part 2): Add global damping
            }

            // Reset all forces on each mass
            m->forces = Vector2D(0, 0);
        }
    }

    void Rope::simulateVerlet(float delta_t, Vector2D gravity)
    {
        for (auto &s : springs)
        {
            // TODO (Part 3): Simulate one timestep of the rope using explicit Verlet （solving constraints)
        }

        for (auto &m : masses)
        {
            if (!m->pinned)
            {
                Vector2D temp_position = m->position;
                // TODO (Part 3.1): Set the new position of the rope mass
                
                // TODO (Part 4): Add global Verlet damping
            }
        }
    }
}
