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

          if(num_nodes == 0 || num_nodes == 1)
                return;
          for (int i = 0; i < num_nodes - 1; i++)
          {
              if (i == 0)
              {
                  Mass* m1 = new Mass(start, node_mass, false);
                  masses.push_back(m1);
                  if (i + 1 == num_nodes-1)
                  {     
                      Mass* m2 = new Mass(end, node_mass, false);
                      springs.push_back(new Spring(m1, m2, k));
                  }
                  else
                  {
                      Mass* m2= new Mass(start + (i + 1)*(end - start) / (num_nodes - 1), node_mass, false);
                      masses.push_back(m2);
                      springs.push_back(new Spring(m1, m2, k));
                  }              
                  
              }              
              else
              {
                Mass* m1= masses[i];
                Mass* m2= new Mass(start + (i + 1)*(end - start) / (num_nodes - 1), node_mass, false);
                masses.push_back(m2);
                springs.push_back(new Spring(m1, m2, k));
              }      

          }
          
       for (auto &i : pinned_nodes) {
           masses[i]->pinned = true;
       }



//         if(num_nodes == 0 || num_nodes == 1)
//             return;
//         Vector2D CurrentPosition = start;
//         //treat rope as a list
//         Mass * p = new Mass(start,node_mass,false);
//         masses.push_back(p);
//         Mass * l = nullptr;
//         Spring * presentSpring = nullptr;
//         for(int i = 1;i <= num_nodes - 1;i++)
//         {
//             std::cout << i;
//             if(i == (num_nodes -1))
//             {
//                 CurrentPosition = end;
//             }
//             else
//             {
//                 CurrentPosition = start + i * (end-start) / (num_nodes - 1);
//             }
//             l = p;
//             p = new Mass(CurrentPosition,node_mass,false);
//             presentSpring = new Spring(l,p,k);
//             masses.push_back(p);
//             springs.push_back(presentSpring);
//         }
// //        Comment-in this part when you implement the constructor
//         for (auto &i : pinned_nodes) {
//             masses[i]->pinned = true;
//         }
    }

    void Rope::simulateEuler(float delta_t, Vector2D gravity)
    {
        for (auto &s : springs)
        {
            //TODO (Part 2): Use Hooke's law to calculate the force on a node
            auto b = s->m2->position;
            auto a = s->m1->position;
            auto ab = b - a;

            //每个质点施加力
            s->m1->forces += s->k * ab /ab.norm()*(ab.norm() - s->rest_length);
            s->m2->forces -= s->k * ab /ab.norm()*(ab.norm() - s->rest_length);
        }

        for (auto &m : masses)
        {
            if (!m->pinned)
            {
                // TODO (Part 2): Add the force due to gravity, then compute the new velocity and position
                m->forces += gravity * m->mass;

        
                // TODO (Part 2): Add global damping
                //添加摩擦力
                float k_d = 0.01;
                m->forces += - k_d * m->velocity;
                
                //求解加速度
                auto a = m->forces / m->mass;
                //计算速度位置
                m->velocity += a * delta_t;
                m->position += m->velocity * delta_t;
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
